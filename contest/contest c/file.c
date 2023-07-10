#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define TEXT

#ifdef TEXT_1
#define SIZE 100
int main(){
char string[SIZE];
FILE *file, *file_in; 
file = fopen("input.txt", "r");
file_in = fopen("output.txt", "w");

if (file == NULL){
  printf("Not file in the program.\n");
  exit(EXIT_SUCCESS);
}
int i = 0;
fseek(file, 0L, SEEK_END);
int pos =ftell(file);
int l = 0;
while(i < pos){
    i++;
    fseek(file, -i, SEEK_END);
    string[l++] = fgetc(file);
    if (string[l - 1] == '\n' || i == pos){
      for (int j = strlen(string) - 2; j >= 0; j--){
        fprintf(file_in, "%c", string[j]);
      }
      fprintf(file_in, "%c", '\n');
      l = 0;
    }
}
fclose(file);
fclose(file_in);
return 0;
}
#endif

#ifdef TEXT_2
#define SIZE 100
int main(){
FILE *file, *file_in; 
file = fopen("input.txt", "r");
file_in = fopen("output.txt", "w");

if (file == NULL){
  printf("Not file in the program.\n");
  exit(EXIT_SUCCESS);
}
int i = 1;
fseek(file, 0L, SEEK_END);
int pos =ftell(file);
while(i < pos){
    i++;
    fseek(file, -i, SEEK_END);
    fprintf(file_in, "%c",fgetc(file));
}
fclose(file);
fclose(file_in);
return 0;
}
#endif

#ifdef TEXT_3
#define SIZE 100
int main(){
FILE *file; 
file = fopen("input.txt", "r");

if (file == NULL){
  printf("Not file in the program.\n");
  exit(EXIT_SUCCESS);
}
int i = 0;
fseek(file, 0L, SEEK_END);
int pos =ftell(file);
int count = 0;
while(i < pos){
    i++;
    fseek(file, -i, SEEK_END);
    if ((int)fgetc(file) >= 48 && (int)fgetc(file) <= 57)
      count++;
}
fclose(file);
printf("%d", count);
return 0;
}
#endif

#ifdef TEXT_4
#define SIZE 100
void s(char* string, int * i){
  while ((((int)string[*i] >= 48) && ((int)string[*i] <= 57)) && string[*i] != '\n')
    (*i)++;
}

int dige(char* str, int *i){
  char* end = &str[*i];
  while (*end){
    if (isdigit(str[*i])){
      return strtol(end, &end, 10);
    }
    else{
      end++;
      (*i)++;
    }
  }
}

int main(){
  char string[SIZE] = {0};
  FILE *file; 
  file = fopen("input.txt", "r");

  if (file == NULL){
    printf("Not file in the program.\n");
    exit(EXIT_SUCCESS);
  }
  long count = 0;
  int i = 0;
  while(fgets(string, SIZE, file) != NULL){
    i = 0;
    while (string[i] != '\n' && string[i] != '\0'){
      if ((int)string[i] >= 48 && (int)string[i] <= 57){
        count += dige(string, &i);
        s(string, &i);
      }
      i++;
    }
  }
  fclose(file);
  printf("%ld", count);
  return 0;
}
#endif

#ifdef TEXT_5
#define SIZE 100
int count = 0;

struct team{
  char name[SIZE];
  int win;
  int loss;
};

void l(char *str, int *i){
  while ((int)str[*i] >= 48 && (int)str[*i] <= 57)
    (*i)++;
  while ((int)str[*i] < 48 && (int)str[*i] > 57){
    (*i)++;
  }
}

int dige(char* str, int *i){
  char* end = &str[*i];
  while (*end){
    if (isdigit(str[*i])){
      return strtol(end, &end, 10);
    }
    else{
      end++;
      (*i)++;
    }
  }
}

int main(){
  struct team array[10];
  char string[SIZE] = {0};
  FILE *file, *file_in; 
  file = fopen("input.txt", "r");
  file_in = fopen("output.txt", "w");
  if (file == NULL){
    exit(EXIT_SUCCESS);
  }
  int i = 0;
  while(fgets(string, SIZE, file) != NULL){
    char comand_1[12] = {0};
    char comand_2[12] = {0};
    int i = 0, j = 0;
    while (string[i] != ' '){
      comand_1[i] = string[i];
      i++;
    }
    i += 3;
    while (string[i] != ' '){
      comand_2[j] = string[i];
      i++;
      j++;
    }
    i++;
    int flag_1 = 0, flag_2 = 0;
    int x = dige(string, &i);
    l(string, &i);
    int y = dige(string, &i);
    for (int k = 0; k < count; k++){
      if (strcmp(array[k].name, comand_1) == 0){
        flag_1 = 1;
        if (x > y)
          array[k].win += 3;
        else if (x == y)
          array[k].win += 1;
        array[k].loss += (x - y);
      }
      else if (strcmp(array[k].name, comand_2) == 0){
        flag_2 = 1;
        if (x < y)
          array[k].win += 3;
        else if (x == y)
          array[k].win += 1;
        array[k].loss += (y - x);
      }
    }
    if (flag_1 == 0){
      array[count].win = 0;
      array[count].loss = 0;
      strcpy(array[count].name, comand_1);
      if (x > y)
        array[count].win += 3;
      else if (x == y)
        array[count].win += 1;
      array[count].loss += (x - y);
      count++;
    }
    if (flag_2 == 0){
      array[count].win = 0;
      array[count].loss = 0;
      strcpy(array[count].name, comand_2);
      if (x < y)
        array[count].win += 3;
      else if (x == y)
        array[count].win += 1;
      array[count].loss += (y - x);
      count++;
    }

  }
  int max = 0, max_l = -1000;
  for (int k = 0; k < count; k++){
    if (array[k].win > max && array[count].loss > max_l){
      max = array[k].win;
      max_l = array[k].loss;
    }
  }
  for (int k = 0; k < count; k++){
    if (array[k].win == max && array[k].loss == max_l)
      fprintf(file_in, "%s %d %d\n", array[k].name, array[k].win, array[k].loss);
  }
  fclose(file);
  fclose(file_in);
  return 0;
}
#endif