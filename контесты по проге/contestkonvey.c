#include <stdio.h>
#include <stdlib.h>

int check(int**, int**, int, int, int, int, int);
void print_life(int**, int, int, int);
int count(int**, int, int);
void help(int**, int, int);

int main() {
  int n = 0, m = 0, del = 1;
  scanf("%d %d", &n, &m);
  int** array_dop = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++) {
      array_dop[i] = (int*)calloc(m, sizeof(int));
  }
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++) {
      array[i] = (int*)calloc(m, sizeof(int));
  }

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          scanf("%d", &array[i][j]);
          array_dop[i][j] = array[i][j];
      }
  }

  for (int k = 1; k <= 1000; k++){
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          flag = check(array, array_dop, i, j, n, m, flag);
        }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        array[i][j] = array_dop[i][j];
      }
    }

    if ((k / del == 1)){
      print_life(array, k, n, m);
      del *= 10;
    }

    if (count(array, n, m) == 0 || k == 1000 || flag == 0){
      printf("End life step %d\n", k);
      exit(EXIT_SUCCESS);
    }
  }
  return 0;
}

int count(int** array, int n, int m){ 
  int lives = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (array[i][j] == 1)
        ++lives;
    }
  }
  return lives;
}

void print_life(int** array, int step, int n, int m){
  printf("Step %d: alives %d\n", step, count(array, n , m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (array[i][j] == 1)
        printf("x");
      else
        printf(" ");
    }
    printf("\n");
  }
}

int check(int** array, int** array_dop, int i, int j, int x, int y, int flag) {
  int count_life = 0;
  for (int k = -1; k < 2; k++){
    for (int p = -1; p < 2; p++){
      int left = k, right = p;
      if (p == 0 && k == 0)
        continue;
      if (j + p < 0)
        right = y - 1;
      if (j + p >= y)
        right = -y + 1;
      if (i + k < 0)
        left = x - 1;
      if (i + k >= x)
        left = -x + 1;
      if (array[i + left][j + right] == 1)
        count_life += 1;
    }
  }

  if (count_life == 3 && array[i][j] == 0){
    array_dop[i][j] = 1;
    flag += 1;
  }
  if ((count_life != 3 && count_life != 2) && array[i][j] == 1){
    array_dop[i][j] = 0;
    flag += 1;
  }
  return flag;
}