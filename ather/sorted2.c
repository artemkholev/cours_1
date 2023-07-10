#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int*, int);
void do_array(int*, int);
int* sorted(int*, int, int, int);
int* sorted_f(int*, int, int);

int main(){
  srand(time(NULL));
  int n = 0, m = 10;
  scanf("%d", &n);
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  array = sorted_f(&array[0], n, m);
  print_array(&array[0], n);
  return 0;
}


void print_array(int* array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
  for (int i = 0; i < n; i++){
    array[i] = rand() % 100 + 200;
  }
}

int* sorted_f(int *array, int n, int m){
  int max = array[0];
  for(int i = 0; i < n; i++){
    if (max < array[i])
      max = array[i];
  }
  for (int i = 1; max / i > 0; i*=10){
    array = sorted(array, n, m, i);
  }
  return array;
}

int* sorted(int* array, int n, int m, int del){
  // m - range of values array
  int *array_count = (int*)calloc(m, sizeof(int));
  int *less = (int*)calloc(m, sizeof(int));
  int *array2 = (int*)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++){
    array_count[(array[i] / del) % 10]+= 1;
  }

  less[0] = 0;
  for (int i = 1; i < m; i++){
    less[i] = (array_count[i - 1] + less[i - 1]);
  }

  for (int i = 0; i < n; i++){
    array2[less[(array[i] / del) % 10]] = array[i];
    less[(array[i] / del) % 10]+= 1;
  }
  return array2;
}