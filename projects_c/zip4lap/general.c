#include <stdio.h>
#include "general.h"

unsigned long file_size(FILE *file) {
    fseek(file, 0L, SEEK_END);
    unsigned long len = (unsigned long)ftell(file);
    fseek(file, 0, SEEK_SET);
    return len;
}