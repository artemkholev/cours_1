#include "zip.h"
#include "const.h"
#include "general.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int create_frequency_array(unsigned int *repSymbol, FILE *f_in) {
    unsigned int file_length = file_size(f_in);
    for (int i = 0; i < file_length; ++i)
        repSymbol[(unsigned char)fgetc(f_in)]++;
    return file_length;
}

void create_list(Note_t** head, unsigned int repSymbol, unsigned char symbol) {
    while (*head) {
        if ((*head)->frequency >= repSymbol) break;
        head = &(*head)->next;
    }
    Note_t* new_elem = (Note_t*)malloc(sizeof(Note_t));
    new_elem->left = NULL;
    new_elem->right = NULL;
    new_elem->level = 1;
    new_elem->isSymbol = 1;
    new_elem->frequency = repSymbol;
    new_elem->symbol = symbol;
    new_elem->next = *head;
    *head = new_elem;
}

void turn_symbol_into_code(const Note_t * root, TABLE* table, char *receiving_line, unsigned int *element_position_in_table, int length) {
    if (root->left != NULL && root->right != NULL){
        receiving_line[length] = '1';
        turn_symbol_into_code(root->right, table, receiving_line, element_position_in_table, length + 1);
        receiving_line[length] = '0';
        turn_symbol_into_code(root->left, table, receiving_line, element_position_in_table, length + 1);
        return;
    }
    receiving_line[length] = 0;
    strcpy(table[root->symbol].code, receiving_line);
    table[root->symbol].symbol = root->symbol;
    table[root->symbol].count = root->frequency;
    (*element_position_in_table)++;
}

void write_file(FILE *f_in, char *new_string_code, TABLE* array_sym) {
    int pos_str = 0;
    fseek(f_in, 0, SEEK_SET);
    unsigned char elem_sym = (unsigned char)fgetc(f_in);
    while(!feof(f_in)){
        for (int j = 0; array_sym[elem_sym].code[j] != '\0'; j++)
            new_string_code[pos_str++] = (char)array_sym[elem_sym].code[j];
        elem_sym = (unsigned char)fgetc(f_in);
    }
}

void write_code(int pos, char *string_dictionary, unsigned int dat, int dop){
    for (int i = pos - 1; i >= pos - 8 * dop; i--){
        string_dictionary[i] = (dat % 2) == 1 ? '1' : '0';
        dat /= 2;
    }
}

void make_string_code(char *new_string_code, FILE *f_out, int dictionary_length, TABLE* array_sym, long int max_frequency) {
    int string_length = (int)strlen(new_string_code);
    int tail = string_length % BIT8,
        count = string_length / BIT8,
        length = count + 1;

    int code_length = 0;
    while (max_frequency) {
        code_length++;
        max_frequency /= 2;
    }
    unsigned int byte = (code_length % BIT8 == 0 ? code_length / BIT8 : (code_length / BIT8) + 1);

    unsigned int code_string_size = dictionary_length * BIT8 * byte + BIT8 * 4;
    unsigned int struct_length = dictionary_length;
    char *string_dictionary = (char *)malloc(code_string_size * sizeof(char));

    write_code(BIT8, string_dictionary, tail, COUNT_TAIL_BYTES);
    write_code(BIT8 * 2, string_dictionary, byte, COUNT_ENCODING_BYTES);
    write_code(BIT8 * 4, string_dictionary, struct_length, COUNT_DICTIONARY_BYTES);

    int find_elem = 0;
    for (int i = 0; i < (int)dictionary_length; i++){
        while (!array_sym[find_elem].count) ++find_elem;
        unsigned int count_symbol_in_table = array_sym[find_elem++].count;
        for (int j = BIT8 * byte + 31 + i * BIT8 * byte; j >= 32 + i * BIT8 * byte; j--) {
            string_dictionary[j] = (count_symbol_in_table % 2) ? '1' : '0';
            count_symbol_in_table /= 2;
        }
    }

    BIT_TO_CHAR symbol;
    char *result_dictionary = (char *)malloc((dictionary_length * byte + 4) * sizeof(char));
    for (int i = 0; i < dictionary_length * byte + 4; ++i) {
        symbol.mbit.b1 = (unsigned char) string_dictionary[i * BIT8 + 0];
        symbol.mbit.b2 = (unsigned char) string_dictionary[i * BIT8 + 1];
        symbol.mbit.b3 = (unsigned char) string_dictionary[i * BIT8 + 2];
        symbol.mbit.b4 = (unsigned char) string_dictionary[i * BIT8 + 3];
        symbol.mbit.b5 = (unsigned char) string_dictionary[i * BIT8 + 4];
        symbol.mbit.b6 = (unsigned char) string_dictionary[i * BIT8 + 5];
        symbol.mbit.b7 = (unsigned char) string_dictionary[i * BIT8 + 6];
        symbol.mbit.b8 = (unsigned char) string_dictionary[i * BIT8 + 7];
        result_dictionary[i] = symbol.symb;
    }
    fprintf(f_out, "%c%c%c%c", result_dictionary[0], result_dictionary[1], result_dictionary[2],result_dictionary[3]);
    find_elem = 0;
    for (unsigned int i = 4; i < (int)dictionary_length * byte + 4; i += byte) {
        while (!array_sym[find_elem].count) ++find_elem;
        fprintf(f_out, "%c", array_sym[find_elem++].symbol);
        unsigned int j = i;
        unsigned int count_bytes = byte;
        while (count_bytes--) {
            fprintf(f_out, "%c", result_dictionary[j++]);
        }
    }
    free(result_dictionary);

    for (int i = 0; i < length; ++i) {
        symbol.mbit.b1 = (unsigned char) new_string_code[i * BIT8 + 0];
        symbol.mbit.b2 = (unsigned char) new_string_code[i * BIT8 + 1];
        symbol.mbit.b3 = (unsigned char) new_string_code[i * BIT8 + 2];
        symbol.mbit.b4 = (unsigned char) new_string_code[i * BIT8 + 3];
        symbol.mbit.b5 = (unsigned char) new_string_code[i * BIT8 + 4];
        symbol.mbit.b6 = (unsigned char) new_string_code[i * BIT8 + 5];
        symbol.mbit.b7 = (unsigned char) new_string_code[i * BIT8 + 6];
        symbol.mbit.b8 = (unsigned char) new_string_code[i * BIT8 + 7];
        fprintf(f_out, "%c", symbol.symb);
    }
}

void file_compression(FILE *f_in, FILE *f_out){
    unsigned int repSymbol[SYMBOL_ARRAY_SIZE] = { 0 };
    unsigned int position_of_current_element_in_table = 0;
    int all_symbols_count = 0;
    long int max_frequency = 0;
    char receiving_line[30] = { 0 };
    unsigned int file_length = create_frequency_array( repSymbol, f_in);
    Note_t *head = NULL;
    for (int i = 0; i < SYMBOL_ARRAY_SIZE; i++) {
        if (!repSymbol[i]) continue;
        if (max_frequency < repSymbol[i]) max_frequency = repSymbol[i];
        all_symbols_count++;
        create_list(&head, repSymbol[i], (unsigned char)i);
    }
    head = make_tree_from_list(head);
    TABLE *conversion_table = (TABLE *)malloc(SYMBOL_ARRAY_SIZE * sizeof(TABLE));
    for (int i = 0; i < all_symbols_count; i++){
        memset(conversion_table[i].code, 0, 30);
        conversion_table[i].count = 0;
        conversion_table[i].symbol = 0;
    }
    if (all_symbols_count == 1) {
        conversion_table[head->symbol].code[0] = '0';
        conversion_table[head->symbol].symbol = head->symbol;
        conversion_table[head->symbol].count = head->frequency;
    }
    else turn_symbol_into_code(head, conversion_table, receiving_line, &position_of_current_element_in_table, 0);
    int tree_height = head->level;
    head = delete_tree(head);
    char *new_string_code = (char *)malloc((file_length * tree_height) * sizeof(char));
    write_file(f_in, new_string_code, conversion_table);
    make_string_code(new_string_code, f_out, all_symbols_count, conversion_table, max_frequency);
    free(new_string_code);
    free(conversion_table);
}