#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
struct hash{
    char key[20];
    int value;
};
struct hash** array;
int sliding_hash(const int q, const int p, char* key);
void put(char* key_n, int val, int key_value, int p);
void get(char* key_n, int key_value, int p);
void del(char* key_n, int key_value, int p);
 
int main(){
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
        put(x_2, x_3, key_value, q);
        break;
      case 'G':
        get(x_2, key_value, q);
        break;
      case 'D':
        del(x_2, key_value, q);
        break;
    }
  }
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

void put(char* key_n, int val, int key_value, int p){
  int k = key_value;
  if (size >= p){
    printf("key=%s hash=%d operation=PUT result=overflow\n", key_n, key_value);
    return;
  }

  struct hash* meaning = malloc(sizeof(struct hash));
  meaning->value = val;
  strcpy(meaning->key, key_n);
  if (array[key_value] == NULL || array[key_value]->key[0] == '-'){
    size++;
    array[key_value] = meaning;
    printf("key=%s hash=%d operation=PUT result=inserted value=%d\n", key_n, key_value, val);
    return;
  }

  for(; array[key_value] != NULL && strcmp(array[key_value]->key, key_n) != 0 && array[key_value]->key[0] != '-'; key_value = (key_value + 1) % p);
  printf("key=%s hash=%d operation=PUT result=collision linear_probing=%d value=%d\n", key_n, k, key_value, val);

  if (array[key_value] == NULL || array[key_value]->key[0] == '-'){
    size += 1;
    array[key_value] = meaning;
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