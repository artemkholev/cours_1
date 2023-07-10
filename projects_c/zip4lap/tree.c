#include "tree.h"
#include <stdlib.h>

void create_tree(Note_t** head, Note_t* elem) {
    while (*head) {
        if ((*head)->frequency > elem->frequency) break;
        head = &(*head)->next;
    }
    elem->next = *head;
    *head = elem;
}

Note_t * make_node_from_node(Note_t * left, Note_t * right) {
    Note_t *res = (Note_t*)malloc(sizeof(Note_t));
    res->frequency = left->frequency + right->frequency;
    res->symbol = 0, res->next = 0, res->isSymbol = 0;
    res->left = left, res->right = right;
    if (right->level >= left->level)
        res->level = right->level + 1;
    else
        res->level = left->level + 1;
    return res;
}

Note_t * make_tree_from_list(Note_t * head) {
    while (head && head->next) {
        Note_t *left = head;
        Note_t *right = head->next;
        create_tree(&(head->next->next), make_node_from_node(left, right));
        head = head->next->next;
    }
    return head;
}

Note_t* delete_tree(Note_t* root) {
    if (!root) return NULL;
    root->left = delete_tree(root->left);
    root->right = delete_tree(root->right);
    free(root);
    return NULL;
}
