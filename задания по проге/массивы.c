#define TEXT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifdef TEXT_1
void print_array(int*, int);
void do_array(int*, int);

int main(){
  srand(time(NULL));
  int n = 14, sum = 0, count = 0;
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  for (int i = 0; i < n; i++){
    if (array[i] % 2 == 0 && array[i] >= 0){
      count++;
      sum += array[i];
    }
  }
  printf("Count: %d\nSum: %d\n", count, sum);
  return 0;
}

void print_array(int *array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 10;
  }
}
#endif

#ifdef TEXT_2
void print_array(int*, int);
void do_array(int*, int);
void insertion_sort(int*, int);
void swap(int*, int*);

int main(){
  srand(time(NULL));
  int n = 12, sum = 0, count = 0;
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  insertion_sort(&array[0], n);
  print_array(&array[0], n);
  printf("%d\n", array[0] + array[n - 1]);
  return 0;
}

void print_array(int *array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 10;
  }
}

void insertion_sort(int* array, int n){
  for (int i = 1; i < n; i++){
    for (int j = i; j > 0; j--){
      if (array[j] > array[j - 1])
        swap(&array[j], &array[j - 1]);
    }
  }
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k;
}
#endif

#ifdef TEXT_3
void print_array(int*, int);
void do_array(int*, int);
void insertion_sort(int*, int);
void swap(int*, int*);

int main(){
  srand(time(NULL));
  int n = 12, sum = 0, count = 0;
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  insertion_sort(&array[0], n);
  print_array(&array[0], n);
  printf("SUMA - %d\nRAZN - %d\n", array[0] + array[n - 1], array[0] - array[n - 1]);
  return 0;
}

void print_array(int *array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 10;
  }
}

void insertion_sort(int* array, int n){
  for (int i = 1; i < n; i++){
    for (int j = i; j > 0; j--){
      if (array[j] > array[j - 1])
        swap(&array[j], &array[j - 1]);
    }
  }
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k;
}
#endif

#ifdef TEXT_4
void print_array(int*, int);
void do_array(int*, int);
void swap(int*, int*);

int main(){
  srand(time(NULL));
  int n = 17, sum = 0, count = 0;
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  for (int i = 0; i < n; i++){
    if (array[i] % 2 != 0){
      sum += array[i];
    }
  }
  for (int i = 0; i < n; i++){
    if (array[i] % 3 == 0 )
      swap(&array[i], &sum);
  }
  print_array(&array[0], n);
  return 0;
}

void print_array(int *array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 10;
  }
}

void swap(int* a, int* b){
  *a = *b;
}
#endif

#ifdef TEXT_5
void print_array(double*, int);
void do_array(double*, int);
void insertion_sort_left(double*, int, int );
void insertion_sort_right(double*, int, int );
void swap(double*, double*);

int main(){
  srand(time(NULL));
  int n = 14, sum = 0, count = 0;
  double *array = (double*)calloc(n, sizeof(double));
  do_array(&array[0], n);
  print_array(&array[0], n);
  insertion_sort_left(&array[0], 0, n / 2);
  insertion_sort_right(&array[0], (n / 2), n);
  print_array(&array[0], n);
  return 0;
}

void print_array(double* array, int n){
  for (int i = 0; i < n; i++){
    printf("%.1lf ", array[i]);
  }
  printf("\n");
}

void do_array(double* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = (rand() % 100) * 0.1;
  }
}

void insertion_sort_right(double* array, int left, int right){
  for (int i = left; i < right; i++){
    for (int j = i; j > left; j--){
      if (array[j] > array[j - 1])
        swap(&array[j], &array[j - 1]);
    }
  }
}

void insertion_sort_left(double* array, int left, int right){
  for (int i = left + 1; i < right - 1; i++){
    for (int j = i + 1; j >= 0; j--){
      if (array[j] < array[j - 1])
        swap(&array[j], &array[j - 1]);
    }
  }
}

void swap(double* a, double* b){
  double k = *a;
  *a = *b;
  *b = k;
}
#endif

#ifdef TEXT_6
void print_array(double*, int);
void do_array(double*, int);

int main(){
  srand(time(NULL));
  int n = 12;
  double *array = (double*)calloc(n, sizeof(double));
  do_array(&array[0], n);
  print_array(&array[0], n);
  double max = array[0], min = array[0];
  int pos_max = 0, pos_min = 0;
  for (int i = 0; i < n; i++){
    if (array[i] < min){
      min = array[i];
      pos_min = i;
    }
    if (array[i] > max){
      max = array[i];
      pos_max = i;
    }
  }
  printf("%d\n", (abs(pos_max - pos_min) - 1));
  return 0;
}

void print_array(double *array, int n){
  for (int i = 0; i < n; i++){
    printf("%.1lf| ", array[i]);
  }
  printf("\n");
}

void do_array(double* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 100 * 0.1;
  }
}
#endif

#ifdef TEXT_7
void print_array(int*, int);
void do_array(int*, int);

int main(){
  srand(time(NULL));
  long int n = 15, sum_negative = 0, count_null = 0, multiplication = 1; 
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  for (int i = 0; i < n; i++){
    if (array[i] < 0)
      sum_negative += 1;
    if (array[i] == 0)
      count_null += 1;
    if (array[i] > 0)
      multiplication *= array[i];
  }
  printf("sum_negative: %ld\n count_null: %ld\n multiplication: %ld\n", sum_negative, count_null, multiplication);
  return 0;
}

void print_array(int *array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 10;
  }
}
#endif

#ifdef TEXT_8
void print_array(double*, int);
void do_array(double*, int);

int main(){
  srand(time(NULL));
  int n = 12;
  double *array = (double*)calloc(n, sizeof(double));
  do_array(&array[0], n);
  print_array(&array[0], n);
  double max = array[0], min = array[0];
  for (int i = 0; i < n; i++){
    if (array[i] < min){
      min = array[i];
    }
    if (array[i] > max){
      max = array[i];
    }
  }
  printf("%0.1lf - %0.1lf", min, max);
  return 0;
}

void print_array(double *array, int n){
  for (int i = 0; i < n; i++){
    printf("%.1lf ", array[i]);
  }
  printf("\n");
}

void do_array(double* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 100 * 0.1;
  }
}
#endif

#ifdef TEXT_9
void print_array(int*, int);
void do_array(int*, int);

int main(){
  srand(time(NULL));
  int n = 19, sum = 0;
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  for (int i = 0; i < n; i++){
    if(array[i] > 0)
      sum += array[i];
    else if (array[i] < 0){
      printf("%d\n", sum);
      exit(EXIT_SUCCESS);
    }
  }
  printf("massive have not negative elements\n");
  return 0;
}

void print_array(int *array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 100 - 20;
  }
}
#endif

#ifdef TEXT_10
void print_array(int*, int);
void do_array(int*, int);

int main(){
  srand(time(NULL));
  int n = 16, count = 0;
  int *array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  for (int i = 0; i < n; i++){
    if (array[i] % 3 == 0){
      count++;
      array[i] = 0;
    }
  }
  print_array(&array[0], n);
  printf("Count: %d\n", count);
  return 0;
}

void print_array(int *array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void do_array(int* array, int n){
   for (int i = 0; i < n; i++){
    array[i] = rand() % 10;
  }
}
#endif