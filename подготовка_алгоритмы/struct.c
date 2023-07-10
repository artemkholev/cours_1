#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node* next;
    int val;
};

struct List {
    struct Node* head;
    struct Node* tail;
    int size;
};


struct Node* CreateNode(int val) {
    struct Node* node = (struct Node*)(malloc(sizeof(struct Node)));
    node->val = val;
    node->next = NULL;
    return node;
}

struct List* CreateList() {
    struct Node* node = CreateNode(0);
    struct List* list = (struct List*)(malloc(sizeof(struct List)));
    list->head = node;
    list->tail = node;
    list->size = 0;
    return list;
}


void PushBack(struct List* list, int val) {
    struct Node* node = CreateNode(val);
    list->tail->next = node;
    list->tail = node;
    list->size++;
}

int PopBack(struct List* list) {
    if (list->size == 0) {
        return -1;
    }
    struct Node* iter = list->head;
    for (;iter->next != list->tail; iter = iter->next) {
    }
    int val = list->tail->val;
    free(iter->next);
    iter->next = NULL;
    list->size--;
    list->tail = iter;
    return val;
}


void PushFront(struct List* list, int val) {
    struct Node* node = CreateNode(val);
    node->next = list->head->next;
    list->head->next = node;
    list->size++;
}

int PopFront(struct List* list) {
    if (list->size == 0) {
        return -1;
    }
    struct Node* node = list->head->next->next;
    int val = list->head->next->val;
    free(list->head->next);
    list->head->next = node;
    list->size--;
    return val;
}

void PrintList(struct List* list) {
    for (struct Node* iter = list->head->next; iter != NULL; iter = iter->next) {
        printf("%d ", iter->val);
    }
    printf("\n");
}


struct Stack {
    struct List* list;
};

struct Stack* CreateStack() {
    struct Stack* stack = (struct Stack*)(malloc(sizeof(struct Stack)));
    stack->list = CreateList();
    return stack;
}

void StackPush(struct Stack* stack, int val) {
    PushFront(stack->list, val);
}

int StackPop(struct Stack* stack) {
    return PopFront(stack->list);
}

struct Queue {
    struct List* list;
};

struct Queue* CreateQueue() {
    struct Queue* queue = (struct Queue*)(malloc(sizeof(struct Queue)));
    queue->list = CreateList();
    return queue;
}

void QueuePush(struct Queue* stack, int val) {
    PushBack(stack->list, val);
}

int QueuePop(struct Queue* stack) {
    return PopFront(stack->list);
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
