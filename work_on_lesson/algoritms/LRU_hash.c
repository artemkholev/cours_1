#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//lincked list
struct node{
  int address;
  struct node* next;
  struct node* back;
};

struct node* creat_element(int meaning){
  struct node* element = malloc(sizeof(struct node));
  element->address = meaning;
  element->next = NULL;
  element->next = NULL;
  return element;
}

struct linked_list{
  struct node* tail;
  struct node* head;
};

struct linked_list* create_list(){
  struct node* element = creat_element(0);
  struct linked_list* linked_list = malloc(sizeof(struct linked_list));
  linked_list->tail = element;
  linked_list->head = element;
  return linked_list;
}

void push_b(int v, struct linked_list* linked_list){
  struct node* element = creat_element(v);
  linked_list->tail->next = element;
  linked_list->tail = element;
}

void push_f(int v, struct linked_list* linked_list){
  struct node* element = creat_element(v);
  linked_list->head->next->back = element;
  element->next = linked_list->head->next;
  linked_list->head->next = element;
}

void pop_b(struct linked_list* linked_list){
  if (linked_list->head == 0){
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
}

void pop_f(struct linked_list* linked_list){
  if (linked_list->head == 0){
    printf("No elements\n");
    return;
  }
  struct node* second_element = linked_list->head->next->next;
  free(linked_list->head->next);
  linked_list->head->next = second_element;
} 

void print(struct linked_list* lincked_list){
  struct node* current = lincked_list->head->next;
  while (current != NULL){
    printf("element - %d\n", current->address);
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
}

//
// hash tabl
int size = 0;
struct hash{
    char key[20];
    int value;
};

struct hash** array;
int sliding_hash(const int q, const int p, char* key);
void put(char* key_n, int val, int key_value, int p, struct linked_list* linked_list);
void get(char* key_n, int key_value, int p);
void del(char* key_n, int key_value, int p);
 
int main(){
  struct linked_list* linked_list = create_list();
  int q = 0, p = 0, n = 0;
  char x_1[3] = {0};
  char x_2[10] = {0};
  int x_3 = 0;
  int key_value = 0;
  scanf("%d%d%d", &q, &p, &n);
  array = (struct hash**)malloc(q * sizeof(struct hash*));
  for (int i = 0; i < q; i++)
        array[i] = NULL;
        
  for (int i = n; i > 0; i--){
    scanf("%s", x_1);
    if (x_1[0] == 'P')
      scanf("%s %d", x_2, &x_3);
    else
      scanf("%s", x_2);
    key_value = sliding_hash(q, p, x_2);
    switch (x_1[0]){
      case 'P':
        put(x_2, x_3, key_value, q, linked_list);
        break;
      case 'G':
        get(x_2, key_value, q);
        break;
      case 'D':
        del(x_2, key_value, q);
        break;
    }
  }
  print(linked_list);
  delete(linked_list);
  return 0;
}

int sliding_hash(const int q, const int p, char* key){
  int h = 0, i = -1, mult = 1;
  while (key[++i] != '\0'){
    h = ((key[i] - 'a' + 1) * mult + h) % q;
    mult = (p * mult) % q;
  }
  return h;
}

void put(char* key_n, int val, int key_value, int p, struct linked_list* linked_list){
  int k = key_value;
  if (size >= p){
    printf("key=%s hash=%d operation=PUT result=overflow\n", key_n, key_value);
    int pos = linked_list->tail->address;
    array[pos]->value = val;
    strcpy(array[pos]->key, key_n);
    return;
  }

  struct hash* meaning = malloc(sizeof(struct hash));
  meaning->value = val;
  strcpy(meaning->key, key_n);
  if (array[key_value] == NULL || array[key_value]->key[0] == '-'){
    size++;
    array[key_value] = meaning;
    printf("key=%s hash=%d operation=PUT result=inserted value=%d\n", key_n, key_value, val);
    push_f(key_value, linked_list);
    return;
  }

  for(; array[key_value] != NULL && strcmp(array[key_value]->key, key_n) != 0 && array[key_value]->key[0] != '-'; key_value = (key_value + 1) % p);
  printf("key=%s hash=%d operation=PUT result=collision linear_probing=%d value=%d\n", key_n, k, key_value, val);

  if (array[key_value] == NULL || array[key_value]->key[0] == '-'){
    size += 1;
    array[key_value] = meaning;
    push_f(key_value, linked_list);
    return;
  }
}

void get(char* key_n, int key_value, int p){
  int k = key_value;
  if (array[key_value] != NULL && strcmp(array[key_value]->key, key_n) == 0){
    printf("key=%s hash=%d operation=GET result=found value=%d\n", key_n, key_value, array[key_value]->value);
    return;
  }

  if (array[key_value] == NULL){
    printf("key=%s hash=%d operation=GET result=no_key\n", key_n, key_value);
    return;
  }

  int c = -1;
  while (array[++key_value % p] != NULL){
    if (++c > p)
        break;
    if (strcmp(array[key_value % p]->key, key_n) == 0){
      printf("key=%s hash=%d operation=GET result=collision linear_probing=%d value=%d\n", key_n, k, key_value, array[key_value % p]->value);
      return;
    }
  }

  printf("key=%s hash=%d operation=GET result=collision linear_probing=%d value=no_key\n", key_n, k, key_value % p);
}

void del(char* key_n, int key_value, int p){
  int k = key_value;
  if (array[key_value] != NULL && strcmp(array[key_value]->key, key_n) == 0 ){
    array[key_value]->key[0] = '-';
    array[key_value]->value = -1;
    printf("key=%s hash=%d operation=DEL result=removed\n", key_n, key_value);
    return;
  }

  if (array[key_value] == NULL){
    printf("key=%s hash=%d operation=DEL result=no_key\n", key_n, key_value);
    return;
  }

  while (array[key_value] != NULL) {
      if (strcmp(array[key_value]->key, key_n) == 0) {
          array[key_value]->key[0] = '-';
          array[key_value]->value = -1;
          size--;
          printf("key=%s hash=%d operation=DEL result=collision linear_probing=%d value=removed\n", key_n, k, key_value);
          return;
      }
      key_value = (key_value + 1) % p;
  }
  printf("key=%s hash=%d operation=DEL result=collision linear_probing=%d value=no_key\n", key_n, k, key_value);
  return;
}