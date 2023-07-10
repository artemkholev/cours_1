#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void creature_min(int**, int, int);
void print_array(int**, int);
void print_array_min(int**, int);
void check(int**, int, int, int);

int main(){
  int n = 0, count = 0;
  printf("Enter size field - ");
  scanf("%d", &n);
  printf("Enter numers of mines - ");
  scanf("%d", &count);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(n, sizeof(int));
  }
  creature_min(array, n, count);
  print_array(array, n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (array[i][j] != -1)
        check(array, n, i ,j);
    }
  }

  printf("\nPrint min - ");
  int p = 0;
  scanf("%d", &p);

  if (p == 1)
    print_array_min(array, n);
  return 0;
}

void print_array(int** array, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("%3d", array[i][j]);
    }
    printf("\n");
  }
}

void print_array_min(int** array, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (array[i][j] == -1)
        printf("* ");
      else if (array[i][j] == 0)
        printf(". ");
      else
        printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}

void creature_min(int** array, int n, int count){
  srand(time(NULL));
  int x = 0, y = 0;
  while (count){
    x = rand() % n;
    y = rand() % n;
    if (array[x][y] == 0){
      array[x][y] = -1;
      count -= 1;
    }
  }
}

void check(int** array, int n, int i, int j){
  int count = 0;
  for (int k = - 1; k < 2; k++){
    for(int p = -1; p < 2; p++){
      if ((k == 0 && p == 0) || i + k < 0 || j + p < 0 || i + k >= n || j + p >= n)
        continue;
      if (array[i + k][j + p] == -1)
        count += 1;
    }
  }
  if (count)
    array[i][j] = count;
}