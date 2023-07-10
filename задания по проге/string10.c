#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT
#define size 20

#ifdef TEXT_prob
int main(){
  char string[] = "hello how are you";
  char* pch = strtok(string, " ");
  while (pch != NULL){
    printf("%s\n", pch);
    pch = strtok(NULL, " ");
  }
  return 0;
}
#endif

#ifdef TEXT_1
void print(char* string){
  char letters[] = "AEIOUYaeiouy";
  int i = 0, flag = 0, count = 0;
  
  while (string[i] != '\n'){
    if (string[i] == ' '){
      flag = 0;
      count = 0;
      i++;
    }
    else{
      if (flag == 0){
        flag = 1;
        int j = 0;
        while (letters[j] != '\0'){
          if (string[i] == letters[j]){
            while (string[i] != ' ' && string[i] != '\n')
              i++;
            j = -1;
            break;
          }
          j++;
        }
        if (j != -1){
          while (string[i] != '\n' && string[i] != ' '){
            count += (int)string[i++];
          }
          printf("%d ", count);
        }
      }
    }
  }
}

int main(){
  char string[size] = {0};
  fgets(string, size, stdin);
  print(string);
  return 0;
}
#endif

#ifdef TEXT_2
char* print(char* string){
  int i = 0, flag = 0, count = 0;
  char* array = malloc(size);
  while (string[i] != '\n'){
    if (string[i] == ' '){
      flag = 0;
      i++;
    }
    else{
      if (flag == 0){
        flag = 1;
        while (string[i] != '\n' && string[i] != ' ')
          i++;
        array[count] = string[i - 1];
        string[count++] = string[i - 1];
      }
    }
  }
  while (string[count] != '\n'){
    string[count++] = 0;
  }
  return array;
}

int main(){
  char string[size] = {0};
  fgets(string, size, stdin);
  //print(string);
  char* array;
  array = print(string);
  for (int i = 0; array[i] != '\0'; i++)
    printf("%c",array[i]);
  return 0;
}
#endif

#ifdef TEXT_3
char* print(char* string){
  int i = 0, flag = 0, count = 0;
  char* array = malloc(size);
  while (string[i] != '\n'){
    if (string[i] == ' '){
      flag = 0;
      i++;
    }
    else{
      if (flag == 0){
        if ((string[++i] != ' ' || string[i] != '\0') && flag == 0){ 
          array[count++] = string[i];
          flag = 1;
        }
        while (string[i] != '\n' && string[i] != ' ')
          i++;
      }
    }
  }
  while (string[count] != '\n'){
    string[count++] = 0;
  }
  return array;
}

int main(){ 
  char string[size] = {0};
  fgets(string, size, stdin);
  char* array = print(string);
  for (int i = 0; array[i] != '\0'; i++)
    printf("%c",array[i]);
  return 0;
}
#endif

#ifdef TEXT_4
char* print(char* string){
  int i = 0, flag = 0, count = 0;
  char* array = malloc(size);
  while (string[i] != '\n'){
    // if (string[i] == ' '){
    //   flag = 0;
    //   i++;
    // }
    // else{
    //   if (flag == 0){
    //     flag = 1;
    //     while (string[i] != '\n' && string[i] != ' '){
    //       if (i % 2 == 0)
    //         array[count++] = string[i];
    //       i++;
    //     }
    //   }
    // }
    if (i % 2 == 0)
      array[count++] = string[i];
    i++;
  } 
  return array;
}

int main(){ 
  char string[size] = {0};
  fgets(string, size, stdin);
  char* array = print(string);
  for (int i = 0; array[i] != '\0'; i++)
    printf("%c",array[i]);
  return 0;
}
#endif

#ifdef TEXT_5
int find(char* string, char simbol){
  int i = 0;
  int flag = 0;
  while (string[i]){
    if (string[i] == simbol){
      flag = 1;
      break;
    }
    i++;
  }
  if (flag == 0)
    return -1;
  else 
    return i + 1;
}

int main(){ 
  char string[size] = {0};
  char simbol;
  fgets(string, size, stdin);
  scanf("%c", &simbol);  
  printf("%d", find(string, simbol));
  return 0;
}
#endif