#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* next;
    struct Node* prev;
    int val;
};

struct List {
    struct Node* head;
    int size;
};


struct Node* CreateNode(int val) {
    struct Node* node = (struct Node*)(malloc(sizeof(struct Node)));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct List* CreateList() {
    struct Node* node = CreateNode(0);
    struct List* list = (struct List*)(malloc(sizeof(struct List)));
    list->head = node;
    node->next = node;
    node->prev = node;
    list->size = 0;
    return list;
}


void PushBack(struct List* list, int val) {
    struct Node* node = CreateNode(val);
    list->head->prev->next = node;
    node->next = list->head;
    node->prev = list->head->prev;
    list->head->prev = node;
    list->size++;
}

int PopBack(struct List* list) {
    if (list->size == 0) {
        return -1;
    }

    int val = list->head->prev->val;
    struct Node* node = list->head->prev;
    list->head->prev = node->prev;
    list->head->prev->next = list->head;
    free(node);
    list->size--;
    return val;
}


void PushFront(struct List* list, int val) {
    struct Node* node = CreateNode(val);
    list->head->next->prev = node;
    node->prev = list->head;
    node->next = list->head->next;
    list->head->next = node;
    list->size++;
}

int PopFront(struct List* list) {
    if (list->size == 0) {
        return -1;
    }
    int val = list->head->next->val;
    struct Node* node = list->head->next;
    list->head->next = node->next;
    list->head->next->prev = list->head;
    free(node);
    list->size--;
    return val;
}

void PrintList(struct List* list) {
    for (struct Node* iter = list->head->next; iter != list->head; iter = iter->next) {
        printf("%d ", iter->val);
    }
    printf("\n");
}

int main() {
    struct List* list = CreateList();
    PrintList(list);
    PushBack(list, 10);
    PrintList(list);
    PushFront(list, 12);
    PrintList(list);
    PushFront(list, 23);
    PrintList(list);
    printf("%d\n", PopBack(list));
    PrintList(list);
    printf("%d\n", PopFront(list));
    PrintList(list);
    printf("%d\n", PopBack(list));
    PrintList(list);
    return 0;
}
