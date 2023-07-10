#define TEXT
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef TEXT_1
int main(){
  int size = 0, f = 0;
  scanf("%d %d", &size, &f);
  int* array = (int*)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++){
    scanf("%d", &array[i]);
  }
  printf("Initial array:\n");
  for (int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\nTarget element: %d\n", f);
  int flag = 0;
  for (int i = 0; i < size; i++){
    if (array[i] == f){
      if (flag == 0)
        printf("Target is found at: ");
      flag = 1;
      printf("%d ", i);
    }
  }
  if (flag == 0)
    printf("No targets");
  return 0;
}
#endif

#ifdef TEXT_2
void binsearch(int*, int, int);

int main(){
  int size = 0, f = 0;
  scanf("%d %d", &size, &f);
  int* array = (int*)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++){
    scanf("%d", &array[i]);
  }
  printf("Initial array:\n");
  for (int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\nTarget element: %d\nSearch history: ", f);
  binsearch(&array[0], size, f);
  return 0;
}

void binsearch(int* array, int size, int f){
  int left = 0, middle = 0;
  int right = size - 1;
  while (left <= right){
    middle = (left + right) / 2;
    printf("%d(%d) ", array[middle], middle);
    if (f == array[middle]){
      printf("\nTarget is found at: %d", middle);
      exit(EXIT_SUCCESS);
    }
    else if (f < array[middle])
      right = middle - 1;
    else
      left = middle + 1;
  }
  printf("\nNo targets");
}
#endif

#ifdef TEXT_3
void binsearch(int*, int, int, int);

int main(){
  int size = 0, f = 0;
  scanf("%d %d", &size, &f);
  int* array = (int*)calloc(size, sizeof(int));
  for (int i = 0; i < size; i++){
    scanf("%d", &array[i]);
  }
  printf("Initial array:\n");
  for (int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\nTarget element: %d\nBounds history: ", f);
  int step = 1;
  int pos = 0;
  while (1){
    printf("%d(%d) ", array[pos], pos);
    if (array[0] > f ){
      printf("\nNo targets");
      exit(EXIT_SUCCESS);
    }
    if (array[pos] == f && pos < size){
      printf("\nTarget is found at: %d", pos);
      exit(EXIT_SUCCESS);
    }
    else if (f < array[pos] && pos < size){
      if (pos - pos /2 != 1)
        binsearch(&array[0], (pos) / 2 + 1, pos - 1, f);
      else{
        printf("\nNo targets");
        exit(EXIT_SUCCESS);
      }
    }
    else{
      pos = step;
      if (pos > size && pos / 2 >= size - 1){
        printf("\nNo targets");
        exit(EXIT_SUCCESS);
      }
      if (pos > size - 1){
        if (array[size - 1] < f || size - 1 < pos){
          binsearch(&array[0], (pos) / 2 + 1, size - 1, f);
        }
        pos = size - 1;
        continue;
      }
      step *= 2;
    }
  }
  return 0;
}

void binsearch(int* array, int l, int r, int f){
  int left = l, middle = 0;
  int right = r;
  printf("\nSearch history: ");
  while (left <= right){
    middle = (left + right) / 2;
    printf("%d(%d) ", array[middle], middle);
    if (f == array[middle]){
      printf("\nTarget is found at: %d", middle);
      exit(EXIT_SUCCESS);
    }
    else if (f < array[middle])
      right = middle - 1;
    else
      left = middle + 1;
  }
  printf("\nNo targets");
  exit(EXIT_SUCCESS);
}
#endif

#ifdef TEXT_4
void do_array(int*, int);
void print_array(int*, int);
void quick_sort(int*, int, int);
int quick_help(int*, int, int);
void swap(int*, int*);
void interpolation(int*, int, int, int);

int main(){
  int n = 0;
  scanf("%d", &n);
  int* array = (int*)calloc(n, sizeof(int));
  do_array(array, n);
  print_array(array, n);
  quick_sort(array, 0, n - 1);
  print_array(array, n);

  int f = 0;
  scanf("%d", &f);
  interpolation(array, f, 0, n - 1);
  return 0;
}

void interpolation(int* array, int f, int left, int right){
  if (left < right){
    int pos = left + ((f - array[left]) / (array[right] - array[left]) * (right - left));
    if (array[pos] == f || array[0] == f)
      printf("Position - %d\n", pos + 1);
    else if(array[pos] > f){
      right = pos - 1;
      interpolation(array, f, left, right);
    }
    else{
      left = pos + 1;
      interpolation(array, f, left, right);
    }
  }
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k; 
}

void quick_sort(int* array, int left, int right){
  if (left >= right)
    return;
  int pivot = quick_help(array, left, right);
  quick_sort(array, left, pivot - 1);
  quick_sort(array, pivot + 1, right);
}

int quick_help(int* array, int left, int right){
  srand(time(NULL));
  int partition = left + (rand() % (right - left));
  if (partition != right){
    swap(&array[partition], &array[right]);
  }
  partition = array[right];

  int ind = left;
  for (int i = left; i < right; ++i){
    if (array[i] < partition){
      swap(&array[i], &array[ind]);
      ++ind;
    }
  }
  swap(&array[ind], &array[right]);
  return ind;
}

void do_array(int* array, int n){
  srand(time(NULL));
  for (int i = 0; i < n; ++i){
    array[i] = rand() % 20;
  }
}

void print_array(int* array, int n){
  for (int i = 0; i < n; ++i){
    printf("%d ", array[i]);
  }
  printf("\n");
}
#endif