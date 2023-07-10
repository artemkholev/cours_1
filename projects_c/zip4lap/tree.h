#ifndef ZIP4LAP_TREE_H
#define ZIP4LAP_TREE_H
#include "const.h"
#include <stdbool.h>

typedef struct node {
    unsigned char symbol; //Храним символ
    bool isSymbol; //Храним признак символа
    unsigned int frequency; //Частота встречаемости узла
    unsigned char code[CODE_SIZE]; //Битовый код символа
    int level; //Уровень глубины дерева
    struct node * left, *right, *next;
} Note_t;

void create_tree(Note_t** head, Note_t* elem);
Note_t * make_node_from_node(Note_t * left, Note_t * right);
Note_t * make_tree_from_list(Note_t * head);
Note_t* delete_tree(Note_t* root);

#endif //ZIP4LAP_TREE_H
