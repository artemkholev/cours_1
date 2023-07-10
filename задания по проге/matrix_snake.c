#include <stdio.h>
#include <stdlib.h>

void f1(int** array, int n){
  int count = 1;
  for(int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      array[i][j] = count++;
  }
}

void f2(int** array, int n){
  int count = 1;
  int pos = 0;
  for (int i = 0; i < n; i++){
    if (pos % 2 == 0){
      for (int j = 0; j < n; j++)
        array[i][j] = count++;
    }
    else{
      count += n - 1;
      for (int j = 0; j < n; j++)
        array[i][j] = count--;
      count += n + 1;
    }
    pos++;
  }
}

void f3(int** array, int n){
  int count = 1;
  for (int i = 0; i < n; i++){
    for (int j = i; j < n - i; j++)
      array[i][j] = count++;
    if (count > n * n) break;
    for (int j = i + 1; j < n - i - 1; j++)
      array[j][n - 1 - i] = count++;
    for (int j = n - i - 1; j >= i; j--)
      array[n - 1 - i][j] = count++;
    for (int j = n - i - 2; j > i; j--)
      array[j][i] = count++;
  }
}

void f4(int** array, int n){
  int count = 1, right = 3;
  for (int j = 0; j < 2; j++)
    array[0][j] = count++;
  for (int j = 2 - 1; j >= 0 && n > 1; j--)
    array[1][j] = count++;

  for (int i = 0; i < n; i++){
    if (count > n * n || right == n + 1) break;
    for (int j = 0; j < right; j++)
      array[right - 1][j] = count++;

    for (int j = right - 2; j >= 0; j--)
      array[j][right - 1] = count++;
    right++;

    if (count > n * n || right == n + 1) break;
    for (int j = 0; j < right; j++)
      array[j][right - 1] = count++;
      
    for (int j = right - 2; j >= 0; j--)
      array[right - 1][j] = count++;
    right++;
  }
}

int main(){
  int n = 0, v = 0;
  scanf("%d", &n);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++)
    array[i] = (int*)calloc(n, sizeof(int));
  scanf("%d", &v);
  switch (v){
  case 1:
    f1(array, n);
    break;
  case 2:
    f2(array, n);
    break; 
  case 3:
    f3(array, n);
    break;
  case 4:
    f4(array, n);
    break;
  default:
    break;
  }
  for (int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      printf("%3d", array[i][j]);
    printf("\n");
  }
  return 0;
}