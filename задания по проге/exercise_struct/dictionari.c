#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define MAXSIZE 1000 
#define LENGHT 20  /* максимальная длина слова */ 


struct elem {
 char *word;
 struct info *data;
}; 

struct info { 
 int count;       /* количество повторений слова в данном тексте */ 
 char *alias;     /* синоним данного слова */ 
}; 

struct dictionary{ 
 struct elem *tabl[MAXSIZE]; 
 int number;      /* количество слов в словаре */ 
};

void clearDict(struct dictionary *dict){
  for (int i = 0; i < dict->number; i++){
    free(dict->tabl[i]->word);
    free(dict->tabl[i]->data->alias);
    free(dict->tabl[i]->data);
    free(dict->tabl[i]);
  }
}

void downWord(char *str, int len){
  for (int i = 0; i < len; i++){
    str[i] = (char)tolower(str[i]);
  }
}

int findWord(struct dictionary *dict, char *strWard){
  for (int i = 0; i < dict->number; i++){
    if ( !strcmp(dict->tabl[i]->word, strWard) ){
      return i;
    }
  }
  return -1;
}

void printS(){
  printf("-------------------------------------------------------\n");
}

void init(struct dictionary *dict){
  dict->tabl[dict->number] = (struct elem*)malloc(sizeof(struct elem));
  dict->tabl[dict->number]->word = (char*)calloc(LENGHT + 1, sizeof(char));
  dict->tabl[dict->number]->data = (struct info*)malloc(sizeof(struct info));
  dict->tabl[dict->number]->data->count = 1;
  dict->tabl[dict->number]->data->alias = (char*)calloc(LENGHT + 1, sizeof(char));
}

void find(struct dictionary *dict){
  printf("input word that need to find: ");
  char fWord[LENGHT + 1] = {0};
  scanf("%s", fWord);
  downWord(fWord, (int)strlen(fWord));
  int posEl = findWord(dict, fWord);
  if (posEl != -1){
    printf("Your element located in: %d\n", posEl);
  } else{
    printf("Your element located in: None\n");
  }
  printS();
}

void often(struct dictionary *dict){
  int max = 0;
  int pos = -1;
  for (int i = 0; i < dict->number; i++){
    if (dict->tabl[i]->data->count > max){
      max = dict->tabl[i]->data->count;
      pos = i;
    }
  }
  if (pos == -1){
    printf("Not words\n");
  } else{
    printf("Word that often finded in dictionary is:\nword: %s;\ncount of repeats: %d;\nposition: %d\n", dict->tabl[pos]->word, max, pos);
  }
  printS();
}

void all(struct dictionary *dict){
  char string[26] = "abcdefghijklmnopqrstuvwxyz";
  int flag = 0;
  for (int i = 0; i < 26; i++){
    for (int j = 0; j < dict->number; j++){
      if ( string[i] == dict->tabl[j]->word[0] ){
        flag++;
        break;
      }
    }
  }
  if (flag == 26){
    printf("Yes, finded\n");
  } else{
    printf("No, finded\n");
  }
  printS();
}

void max(struct dictionary *dict){
  int* array = (int*)calloc(26, sizeof(int));
  for (int i = 0; i < 26; i++){
    for (int j = 0; j < dict->number; j++){
      if ( (i + 'a') == (char)dict->tabl[j]->word[0] ){
        array[i]++;
      }
    }
  }
  int max = 0, pos = 0;
  for (int i = 0; i < 26; i++){
    if (array[i] > max){
      max = array[i];
      pos = i;
    }
    printf("|%c:%d| ", ('a' + i), array[i]);
  }
  printf("\n");
  printf("\nMax count words:\n");
  for (int i = 0; i < 26; i++){
    if (array[i] == max)  
      printf("letter - %c; count - %d\n", 'a' + i, array[i]);
  }
  printS();
  free(array);
}

void syn(struct dictionary *dict){
  int flag = 0;
  for (int i = 0; i < dict->number - 1; i++){
    for (int j = i + 1; j < dict->number; j++){
      if ( dict->tabl[i]->data->alias[0] != '\0' && !strcmp(dict->tabl[i]->data->alias, dict->tabl[j]->data->alias) && strcmp(dict->tabl[i]->word, dict->tabl[j]->word) ){
        if (flag++ == 0){
          printf("there are synonyms\n");
        }
        printf("words: %s, %s; synonym: %s\n", dict->tabl[i]->word, dict->tabl[j]->word, dict->tabl[i]->data->alias);
      }
    }
  }
  if (flag == 0){
    printf("No synonyms\n");
  }
  printS();
}

void esyn(struct dictionary *dict){
  char str[LENGHT + 1] = {0};
  printf("enter word - ");
  scanf("%s", str);
  for (int i = 0; i < dict->number; i++){
    if ( !strcmp(dict->tabl[i]->word, str)){
      printf("enter synonym: ");
      scanf("%s",  dict->tabl[i]->data->alias);
      printS();
      return;
    }
  }
  printf("No word, it not find in dictionary\n");
  printS();
}

int cmp(const void * a, const void * b) {
    return strcmp(*(char**)a, *(char**)b);
}

void sorted(struct dictionary *dict){
  qsort(dict->tabl, (long unsigned int)dict->number, sizeof(char*), cmp);
}

int main() {
  char string[LENGHT + 1] = {0};
  struct dictionary dict = {0};

  FILE *fileOpen = fopen("input.txt", "r");
  while ( fscanf(fileOpen, "%s", string) == 1 ){
    int len = (int)strlen(string);
    downWord(string, len);
    // correct form word
    if (string[len - 1] == '.' || string[len - 1] == ',' || string[len - 1] == ':' || string[len - 1] == '\n')
      string[len] = '\0';

    // find element in dictionary, if not find do new instanc  
    int posEl = findWord(&dict, string);
    if ( posEl == -1){
      init(&dict);
      strcpy(dict.tabl[dict.number]->word, string);
      dict.number++;
    } else{
      dict.tabl[posEl]->data->count++;
    }

    // clear string for new iteration
    memset(string, 0, LENGHT);
  }
  fclose(fileOpen);
  sorted(&dict);
  printf("\nNumber words: %d\n", dict.number);
  printS();

  // entered word
  char str[LENGHT + 1] = {0};
  scanf("%s", str);
  while ( strcmp(str, "close") ){
    // find element
    if ( !strcmp(str, "find") ){
      find(&dict);
    } else if ( !strcmp(str, "often" )){
      often(&dict);
    } else if ( !strcmp(str, "all") ) {
      all(&dict);
    } else if ( !strcmp(str, "max") ){
      max(&dict);
    } else if ( !strcmp(str, "esyn") ){
      esyn(&dict);
    } else if ( !strcmp(str, "syn") ){
      syn(&dict);
    } else {
      printf("Not find command:(\n");
    }

    memset(str, 0, LENGHT);
    scanf("%s", str);
  }

  // for (int i = 0; i < dict.number; i++){
  //   printf("%s ", dict.tabl[i]->word);
  // }
  clearDict(&dict);
  return 0;
}