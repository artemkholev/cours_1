#include "const.h"
#include "general.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int bin_to_dec_conv(const int bin[], int bin_size) {
    int pow_two = 1, dec = 0;
    for (int i = bin_size-1; i >= 0; --i) {
        dec += bin[i] * pow_two;
        pow_two *= 2;
    }
    return dec;
}

void get_bits_from_byte(char byte, int* bits_arr) {
    BIT_TO_CHAR BTC;
    BTC.symb = byte;
    bits_arr[0] = BTC.mbit.b1;
    bits_arr[1] = BTC.mbit.b2;
    bits_arr[2] = BTC.mbit.b3;
    bits_arr[3] = BTC.mbit.b4;
    bits_arr[4] = BTC.mbit.b5;
    bits_arr[5] = BTC.mbit.b6;
    bits_arr[6] = BTC.mbit.b7;
    bits_arr[7] = BTC.mbit.b8;
}

int parse_n_bytes_to_int(FILE* file, int bytes_num) {
    int current_bit = 0;
    int *bits = (int*)calloc(bytes_num * BIT8, sizeof(int));
    for (int b = 0; b < bytes_num; ++b) {
        char byte;
        fread(&byte, 1, 1, file);
        get_bits_from_byte(byte, &bits[current_bit]);
        current_bit += BIT8;
    }
    int int_value = bin_to_dec_conv(bits, bytes_num * BIT8);
    free(bits);
    return int_value;
}

int get_repetition_table(int *repetition_table, FILE* file) {
    int value_length = parse_n_bytes_to_int(file, COUNT_ENCODING_BYTES);
    int symbols_count = parse_n_bytes_to_int(file, COUNT_DICTIONARY_BYTES);

    for (int i = 0; i < symbols_count; ++i) {
        int key = 0;
        fread(&key, 1, 1, file);
        repetition_table[key] = parse_n_bytes_to_int(file, value_length);
    }
    return symbols_count * value_length + symbols_count;
}

void file_decompression(FILE *file_read, FILE *file_write) {
    unsigned long file_read_length = file_size(file_read);

    int tail_length = parse_n_bytes_to_int(file_read, COUNT_TAIL_BYTES);

    int repetition_symbol[SYMBOL_ARRAY_SIZE] = {0};
    int repetition_table_size = get_repetition_table(repetition_symbol, file_read);

    Note_t *head = NULL;
    for (int i = 0; i < SYMBOL_ARRAY_SIZE; i++)
        if (repetition_symbol[i])
            create_list(&head, repetition_symbol[i], (char) i);


    head = make_tree_from_list(head);

    Note_t *current_tree_branch = head;
    unsigned long archive_length = file_read_length - (COUNT_TAIL_BYTES + COUNT_ENCODING_BYTES + COUNT_DICTIONARY_BYTES + repetition_table_size);

    for (int i = 0; i < archive_length; ++i) {
        char byte;
        fread(&byte, 1, 1, file_read);
        int bits[BIT8];
        get_bits_from_byte(byte, bits);

        int sign_bits = BIT8;
        if (i == archive_length - 1) sign_bits = tail_length;
        for (int b = 0; b < sign_bits; ++b) {
            if (bits[b] == LEFT_BRANCH && current_tree_branch->left) {
                current_tree_branch = current_tree_branch->left;
            }
            else if (bits[b] == RIGHT_BRANCH && current_tree_branch->right) {
                current_tree_branch = current_tree_branch->right;
            }
            if (current_tree_branch->isSymbol != true) continue;
            fprintf(file_write, "%c", current_tree_branch->symbol);
            current_tree_branch = head;
        }
    }
    delete_tree(head);
}