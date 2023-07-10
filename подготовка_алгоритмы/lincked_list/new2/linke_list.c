#include <stdio.h>
#include <stdlib.h>

struct node{
  int value;
  struct node* next;
};

struct node* creat_element(int meaning){
  struct node* element = malloc(sizeof(struct node));
  element->value = meaning;
  element->next = NULL;
  return element;
}

struct linked_list{
  struct node* tail;
  struct node* head;
  int size_list;
};

struct linked_list* create_list(){
  struct node* element = creat_element(0);
  struct linked_list* linked_list = malloc(sizeof(struct linked_list));
  linked_list->tail = element;
  linked_list->head = element;
  linked_list->size_list = 0;
  return linked_list;
}

void push_b(int v, struct linked_list* linked_list){
  struct node* element = creat_element(v);
  linked_list->tail->next = element;
  linked_list->tail = element;
  linked_list->size_list += 1;
}

void push_f(int v, struct linked_list* linked_list){
  struct node* element = creat_element(v);
  element->next = linked_list->head->next;
  linked_list->head->next = element;
  linked_list->size_list += 1;
}

void pop_b(struct linked_list* linked_list){
  if (linked_list->size_list == 0){
    printf("No elements\n");
    return;
  }
  struct node* iner = linked_list->head;
  while (iner->next != linked_list->tail){
    iner = iner->next;
  }
  free(iner->next);
  iner->next = NULL;
  linked_list->tail = iner;
  linked_list->size_list -= 1;
}

void pop_f(struct linked_list* linked_list){
  if (linked_list->size_list == 0){
    printf("No elements\n");
    return;
  }
  struct node* second_element = linked_list->head->next->next;
  free(linked_list->head->next);
  linked_list->head->next = second_element;
  linked_list->size_list -=1;
} 

void print(struct linked_list* lincked_list){
  struct node* current = lincked_list->head->next;
  while (current != NULL){
    printf("element - %d\n", current->value);
    current = current->next;
  }
}

void delete(struct linked_list* linked_list){
  struct node* current = linked_list->head;
  struct node* prev;
  while(current != NULL){
    prev = current;
    current = current->next;
    free(prev);
  }
  linked_list->size_list = 0;
}

int main(){
  struct linked_list* linked_list = create_list();
  push_b(1, linked_list);
  push_b(10, linked_list);
  pop_b(linked_list);
  push_f(6, linked_list);
  pop_f(linked_list);
  print(linked_list);
  printf("size - %d\n", linked_list->size_list);
  delete(linked_list);
  return 0;
}