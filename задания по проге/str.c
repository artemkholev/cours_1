#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TEXT

#ifdef TEXT1
void print(int n, char** array){
  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 5 * n; j++){
      if(array[i][j] == '*')
        printf("%c", array[i][j]);
      else
        printf("%c", ' ');
    }
    printf("\n");
  }
}

void do_array(int n, char** array, int pos){
  int k = pos;
  int i = 0;
  for (int j = pos; j < (n * 5 - 1 - n); j++)
    array[i][j] = '*';
  pos = k;
  i++;
  for (int j = pos; j < (5 * n - n); j += 2)
    array[i][j] = '*';
  pos = k;
  i++;
  for (int j = pos; j < (5 * n - n); j += 2)
    array[i][j] = '*';
  pos = k;
  i++;
  for (int j = pos + 2; j < 5 * n - n + 1; j += 2){
    array[i][j] = '*';
  }
  pos = k;
  i++;
  for (int j = pos + 2; j < 5 * n - n + 1; j += 2){
    array[i][j] = '*';
  }
  pos = k;
  i++;
  for (int j = pos + 2; j < 5 * n - n + 1; j++)
    array[i][j] = '*';
}

int main(){
  int n = 0;
  scanf("%d", &n);
  char** array = (char**)malloc(n * 6 *sizeof(char*));
  for (int i = 0; i < (6 * n); i++){
    array[i] = (char*)malloc(5 * n * sizeof(char));
  }
  for (int i = 0; i < n; i++){
    do_array(i + 1, array, i * 4);
  }
  print(n, array);

  return 0;
}
#endif

#ifdef TEXT
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

void skip_sim(char* str, int* i){
  while (((int)str[*i] < '0' || (int)str[*i] > '9') && str[*i] != '\n'){
    (*i)++;
  }
}

void skip_num(char* str, int* i){
  while ((int)str[*i] >= '0' && (int)str[*i] <= '9'){
    (*i)++;
  }
}

int main(){
  float suma = 0;
  char str[1000] = {0};
  fgets(str, 1000,stdin);
  int i = 0;
  while (str[i] != '\n'){
    skip_sim(str, &i);

    if ((str[i - 1] == ' ' || i == 0) && str[i] != '\n'){
      int p = dige(str, &i);
      float d = 0;
      skip_num(str, &i);

      if (str[i] == '.'){
        i++;
        int x = dige(str, &i);
        skip_num(str, &i);
        d = x;
        if (str[i] == ' '){
          while (x){
            d *= 0.1;
            x /= 10;
            i++;
          }
          suma += (d + p);
          continue;
        }
      }

      if(str[i] == ' ' || str[i] == '\n' || str[i] == '.')
        suma += p;
      else 
        skip_sim(str, &i);
    }
    else 
      skip_num(str, &i);
  }
  printf("%.2f", suma);
  return 0;
}
#endif 

// 1sd           sdf1           sdf1sdf      1      1.1           sdf.1         .1dsf        afs.1sdf           ssdf1.1saf     asdf1.1   .1   1.1sdfdsg    