#include "const.h"
#include "zip.c"
#include "unzip.c"
#include <stdio.h>
#include <string.h>

FILE* f_in;
FILE* f_out;
char initial_name[NAME_SIZE] = { 0 };
char result_name[NAME_SIZE] = { 0 };
int command;

int handle_command() {
    f_in = fopen(initial_name, "rb");
    if (!f_in){
        printf("ERROR: open initial file\n");
        return -1;
    }
    f_out = fopen(result_name, "wb");
    if (!f_out){
        printf("ERROR: open/create result file\n");
        fclose(f_in);
        return -2;
    }
    if (command == 1){
        file_compression(f_in, f_out);
        printf("Compressing complete\n");
    } else if (command == 2){
        file_decompression(f_in, f_out);
        printf("Recovering complete\n");
    } else {
        printf("Unknown command\n");
        return -3;
    }
    fclose(f_in);
    fclose(f_out);
    return 0;
}

void input_name() {
    printf("Insert name of original file\n>>> ");
    scanf("%s", initial_name);
    printf("Insert name of result file\n>>> ");
    scanf("%s", result_name);
}

void insert_from_kb(){
    while (1) {
        printf("Insert one of the next commands:\n1 - Compress file\n2 - Recover file\n3 - Open menu\n4 - Exit program\n>>>");
        scanf("%d", &command);
        if (command == 3) continue;
        if (command == 4) break;
        if (command < 0 || command > 4) {
            printf("Incorrect command\n>>>");
            scanf("%d", &command);
            continue;
        }
        input_name();
        handle_command();
        printf("Command complete\n>>>");
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1)
    {
        insert_from_kb();
        return 0;
    }
    if (argc > 4)
    {
        printf("Incorrect format of input");
        return 0;
    }
    strcpy(initial_name, argv[1]);
    strcpy(result_name, argv[2]);
    sscanf(argv[3], "%d", &command);
    return handle_command();
}