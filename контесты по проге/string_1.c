#include <stdio.h>
#include <stdlib.h>
#define TEXT

#ifdef TEXT_1
#define SIZE 100000

int main(){
  int count = 0;
  char string[SIZE] = {0};
  fgets(string, SIZE, stdin);
  int i = 0, flag = 0;
  while (string[i] != '\n'){
    if (string[i] != ' '){
      if (flag == 0){
        count++;
      }
      flag = 1;
    }
    else if (string[i] == ' ')
      flag = 0;
    i++;
  }
  printf("%d", count);
  return 0;
}
#endif

#ifdef TEXT_2
#define SIZE 100000

void swap(char*, char*);

int main(){
  int count = 0, pos_left = 0;;
  char string[SIZE] = {0};
  fgets(string, SIZE, stdin);
  int i = 0, flag = 0;
  while (string[i - 1] != '\n'){
    if (string[i] != ' ' && string[i] != '\n'){
      if (flag == 0){
        pos_left = i;
        count++;
      }
      flag = 1;
    }
    else if ((string[i] == ' ' || string[i] == '\n') && flag == 1){
      if (count % 2 != 0){
        for (int j = i - 1; j > pos_left; j--){
          swap(&string[j], &string[pos_left++]);
        }
      }
      flag = 0;
    }
    i++;
  }
  fputs(string, stdout);
  return 0;
}

void swap(char* a, char* b){
  char k = *a;
  *a = *b;
  *b = k;
}
#endif

#ifdef TEXT_3
#define SIZE 100000

int main(){
  char string[SIZE] = {0};
  fgets(string, SIZE, stdin);
  int i = 0;
  while (string[i] != '\n'){
    if (string[i] != string[i + 1])
      printf("%c", string[i]);
    i++;
  }
  return 0;
}
#endif

#ifdef TEXT_4
#define SIZE 100000

int main(){
  char string[SIZE] = {0};
  fgets(string, SIZE, stdin);
  int i = 0, count = 1;
  while (string[i] != '\n'){
    if (string[i] != string[i + 1]){
      printf("%c", string[i]);
      if (count != 1){
        printf("(%d)", count);
        count = 1; 
      }
    }
    else{
      count++;
    }
    i++;
  }
  return 0;
}
#endif

#ifdef TEXT_5
#define SIZE 100000

int main(){
  char string[SIZE] = {0};
  fgets(string, SIZE, stdin);
  int* array = (int*)calloc(256, sizeof(int));
  int i = 0, flag = 0, count = 0;
  while (string[i] != '\n'){
    if (string[i] == ' '){
      flag = 0;
      i++;
      continue;
    }
    count += 1;
    while (string[i] != ' ' && string[i] != '\n'){
      if (string[i] != '0'){
        array[(int)string[i]] += 1;
        int k = i+1;
        while (string[k] != ' ' && string[k] != '\n'){
          if (string[i] == string[k])
            string[k] = '0';
          k++;
        }
        i++;
      }
      else 
        i++;
    }
  }
  flag = 0;
  printf("Universal: ");
  for (int j = 0; j < 256; j++){
    if (array[j] == count){
      printf("%c ", (char)j);
      flag = 1;
    }
  }
  if (flag == 0)
    printf("no");
  flag = 0;
  printf("\nUnique: ");
  for (int j = 0; j < 256; j++){
    if (array[j] == 1){
      printf("%c ", (char)j);
      flag = 1;
    }
  }
  if (flag == 0)
    printf("no");
  return 0;
}
#endif