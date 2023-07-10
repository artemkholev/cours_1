#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
int count = 0;

struct team{
  char name[SIZE];
  char enemy[10][20];
  int score[10][4];
  int pos;
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

int findComand(struct team *tm, char *comand){
  for (int i = 0; i < tm->pos; i++){
    if (!strcmp(tm->enemy[i], comand)){
      return i;
    }
  }
  return -1;
}

void init(struct team *array){
  array->pos = 0;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 4; j++){
      array->score[i][j] = 0;
    }
  }
}

int main(){
  int count = 0;
  struct team array[10];
  char string[SIZE] = {0};
  FILE *file, *file_in; 
  file = fopen("input.txt", "r");
  file_in = fopen("output.txt", "w");
  if (file == NULL)
    exit(EXIT_SUCCESS);

  int i = 0;
  while(fgets(string, SIZE, file) != NULL){

    //enter data
    char comand_1[20] = {0};
    char comand_2[20] = {0};
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
    
    int x = dige(string, &i);
    l(string, &i);
    int y = dige(string, &i);

    //start

    //update last command
    int flag_1 = 0, flag_2 = 0;
    for (int k = 0; k < count; k++){
      if (strcmp(array[k].name, comand_1) == 0){
        flag_1 = 1;
        int p = findComand(&array[k], comand_2);
        if (p == -1){
          strcpy(array[k].enemy[array[k].pos], comand_2);
          p = array[k].pos;
          array[k].pos++;
        }
        array[k].score[p][0]++;
        if (x > y){
          array[k].score[p][2]++;
        }
        array[k].score[p][3] += x;
      }
      else if (strcmp(array[k].name, comand_2) == 0){
        flag_2 = 1;
        int p = findComand(&array[k], comand_1);
        if (p == -1){
          strcpy(array[k].enemy[array[k].pos], comand_1);
          p = array[k].pos;
          array[k].pos++;
        }
        array[k].score[p][0]++;
        array[k].score[p][1]++;
        if (x < y){
          array[k].score[p][2]++;
        }
        array[k].score[p][3] += y;
      }
    }

    //Add new
    if (flag_1 == 0){
      init(&array[count]);
      strcpy(array[count].name, comand_1);
      strcpy(array[count].enemy[array[count].pos], comand_2);
      int mm = array[count].pos++;
      array[count].score[mm][0]++;
      if (x > y){
        array[count].score[mm][2]++;
      }
      array[count].score[mm][3] += x;
      count++;
    }
    if (flag_2 == 0){
      init(&array[count]);
      strcpy(array[count].name, comand_2);
      strcpy(array[count].enemy[array[count].pos], comand_1);
      int mm = array[count].pos++;
      array[count].score[mm][0]++;
      array[count].score[mm][1]++;
      if (x < y){
        array[count].score[mm][2]++;
      }
      array[count].score[mm][3] += y;
      count++;
    }
  }

  //write result
  for (int i = 0; i < count; i++){
    fprintf(file_in, "%s%s", array[i].name, "\n");
    for (int j = 0; j < array[i].pos; j++){
      fprintf(file_in, "%s%s%d%s%d%s%d%s%d%s", array[i].enemy[j], " ", array[i].score[j][0], " ", array[i].score[j][1], " ", array[i].score[j][2], " ", array[i].score[j][3], "\n");
    }
  }
  fclose(file);
  fclose(file_in);
  return 0;
}