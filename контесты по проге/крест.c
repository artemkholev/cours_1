#include <stdio.h>
#include <stdlib.h>

int p(int x, int n){
    long int a = x, p = 1;
    while (n > 0){
      if ((n % 2) != 0)
          p *= a;
      a *= a;
      n >>= 1;
    }
    return p;
}

void rec(int** array, int n, int pos_x, int pos_y, int step){
  if (n == 0){
    array[pos_x][pos_y] = 1;
    return;
  }
  
  step = step / 3;
  n = n - 1;
  
  rec(array, n, pos_x + step, pos_y, step);
  rec(array, n, pos_x, pos_y + step, step);
  rec(array, n, pos_x, pos_y - step, step);
  rec(array, n, pos_x, pos_y, step);
  rec(array, n, pos_x - step, pos_y, step);
}

int main(){
  int n = 0;
  scanf("%d", &n);
  int k = p(3, n);

  int** array = (int**)calloc(k, sizeof(int*));
  for (int i = 0; i < k; i++){
    array[i] = (int*)calloc(k, sizeof(int));
  }
  int m = k / 2;
  rec(array, n, m, m, k);
  for (int i = 0; i < k; i++){
    for (int j = 0; j < k; j++){
      if(array[i][j] == 0)
        printf(" ");
      else  
        printf("*");
    }
    printf("\n");
  }
  return 0;
}