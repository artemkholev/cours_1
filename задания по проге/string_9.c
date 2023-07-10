#include <stdio.h>
#include <stdlib.h>
#define TEXT
#define size 100

#ifdef TEXT_1
int main(){
  char str[size] = {0};
  fgets(str, size, stdin);
  int i = size - 1;
  while (str[i--] != '\n');
  while (i>=0){
    printf("%c", str[i--]);
  }
  return 0;
}
#endif

#ifdef TEXT_2
int main(){
  char str[size] = {0};
  fgets(str, size, stdin);
  for (int i = 0; i < size; i++){
    if (i % 2 != 0 && (int)str[i] > 96 ){
      str[i]^=0x20;
    }  
    else if(i % 2 == 0 && (int)str[i] < 96 ){
      str[i]^=0x20;
    }
  }
  fputs(str, stdout);
  return 0;
}
#endif

#ifdef TEXT_3
int main(){
  int array[256] = {0};
  char str[size] = {0};
  fgets(str, size, stdin);
  for (int i = 0; i < size && str[i] != '\n'; i++){
    array[(int)str[i]] += 1;
  }
  for (int i = 0; i < 256; i++){
    if (array[i] != 0)
      printf("%c: %d\n", (char)i, array[i]);
  }
}
#endif

#ifdef TEXT_4
int main(){
  char str[size] = {0};
  int count = 0, sum = 0;
  fgets(str, size, stdin);
  for (int i = 0; i < size && str[i] != '\n';){
    while (str[i] == ' ' && str[i] != '\n'){
      i++;
    }
    count += 1;
    while (str[i] != ' ' && str[i] != '\n'){
      if (count % 2 != 0)
        sum +=1;
      i++;
    }
  }
  printf("%d\n", sum);
  return 0;
}
#endif

#ifdef TEXT_5
int main(){
  char str[size] = {0};
  int count = 0;
  fgets(str, size, stdin);
  for (int i = 0; i < size && str[i] != '\n';){
    while (str[i] == ' ' && str[i] != '\n'){
      i++;
    }
    count += 1;
    if (count % 2 == 0){
      while (str[i] != ' ' && str[i] != '\n'){
        str[i]^=0x20;
        i++;
      }
    }
    else{
      while (str[i] != ' ' && str[i] != '\n'){
        i++;
      }
    }
  }
  printf("%s\n", str);
  return 0;
}
#endif 

#ifdef TEXT_6
int main(){
  char str[size] = {0};
  char letters[] = "AEIOUYaeiouy";
  int count = 0, flag = 0;
  fgets(str, size, stdin);
  for (int i = 0; i < size && str[i] != '\n';){
    while (str[i] == ' ' && str[i] != '\n'){
      i++;
    }
    flag = 0;
    for (int j = 0; j < 12; j++){
      if (str[i] == letters[j]){
        i++;
        flag = 1;
        break;
      }
    }
    if (flag == 0){
      count += (int)str[i];
      i++;
      while (str[i] != ' ' && str[i] != '\n'){
        i++;
      }
    }
    else{
      while (str[i] != ' ' && str[i] != '\n'){
        i++;
      }
    }
  }
  printf("%d\n", count);
}
#endif

#ifdef TEXT_7
int main(){
  char str[size] = {0};
  int count = 0;
  fgets(str, size, stdin);
  for (int i = 0; i < size && str[i] != '\n';){
    while (str[i] == ' ' && str[i] != '\n'){
      i++;
    }
    printf("%c", str[i++]);
    while (str[i] != ' ' && str[i] != '\n'){
      i++;
    }
  }
}
#endif