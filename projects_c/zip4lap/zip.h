#ifndef ZIP4LAP_ZIP_H
#define ZIP4LAP_ZIP_H
#include "tree.c"
#include <stdio.h>

typedef struct character_code {
    unsigned char symbol; //Храним символ
    char code[30]; //Битовый код символа
    unsigned int count;
} TABLE;

typedef union bit_to_char {
    char symb;
    struct bit {
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned b4 : 1;
        unsigned b5 : 1;
        unsigned b6 : 1;
        unsigned b7 : 1;
        unsigned b8 : 1;
    }mbit;
}BIT_TO_CHAR;

void file_compression(FILE *f_in, FILE *f_out);
unsigned int create_frequency_array(unsigned int *repSymbol, FILE *f_in);
void create_list(Note_t** head, unsigned int repSymbol, unsigned char symbol);
void turn_symbol_into_code(const Note_t * root, TABLE* table, char *receiving_line, unsigned int *element_position_in_table, int length);
void write_file(FILE *f_in, char *new_string_code, TABLE* array_sym);
void write_code(int pos, char *string_dictionary, unsigned int dat, int dop);
void make_string_code(char *new_string_code, FILE *f_out, int dictionary_length, TABLE* array_sym, long int max_frequency);

#endif //ZIP4LAP_ZIP_H
