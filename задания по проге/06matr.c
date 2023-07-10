#define TEXT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef TEXT_1
void print_2d_arr(int**, int, int);

int main(){
  srand(time(NULL));
  int n = 0, m = 0;
  int suma = 0;
  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      array[i][j] = rand() % 10;
    }
  }
  print_2d_arr(array, n, m);

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      suma += array[i][j];
    }
  }
  printf("%d\n", suma);
  return 0;
}

void print_2d_arr(int** array, int n, int m){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}
#endif

#ifdef TEXT_2
void print_2d_arr(int**, int, int);
void print_array(int*, int);

int main(){
  srand(time(NULL));
  int n = 0, m = 0;
  int pos = 0;

  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  int* array_max_min = (int*)calloc(n * 2, sizeof(int));

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      array[i][j] = rand() % 10;
    }
  }
  print_2d_arr(array, n, m);

  for (int i = 0; i < n; ++i){
    int max = array[i][0], min = array[i][0];
    for (int j = 1; j < m; ++j){
      if (array[i][j] < min)
        min = array[i][j];
      if (array[i][j] > max)
        max = array[i][j];
    }
    array_max_min[pos] = min;
      pos++;
    array_max_min[pos] = max;
      pos++;
  }
  print_array(&array_max_min[0], n);
  return 0;
}

void print_2d_arr(int** array, int n, int m){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_array(int* array, int n){
  for (int i = 0; i < n * 2; ++i){
    printf("%d ", array[i]);
    if (i % 2 != 0) printf("\n");
  }
}
#endif

#ifdef TEXT_3
void print_2d_arr(int**, int, int);
void swap(int*, int*);

int main(){
  srand(time(NULL));
  int n = 0, m = 0;

  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      array[i][j] = rand() % 10;
    }
  }
  print_2d_arr(array, n, m);

  int pos_max = 0, pos_min = 0;
  for (int i = 0; i < n; ++i){
    int max = array[i][0], min = array[i][0];
    for (int j = 1; j < m; ++j){
      if (array[i][j] < min){
        min = array[i][j];
        pos_min = j;
      }
      if (array[i][j] > max){
        max = array[i][j];
        pos_max = j;
      }
    }
    swap(&array[i][pos_max], &array[i][pos_min]);
  }

  print_2d_arr(array, n, m);
  return 0;
}

void print_2d_arr(int** array, int n, int m){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k;
}
#endif

#ifdef TEXT_4
void print_2d_arr(int**, int, int);
void swap(int*, int*);

int main(){
  srand(time(NULL));
  int n = 0, m = 0;

  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      array[i][j] = rand() % 10;
    }
  }
  print_2d_arr(array, n, m);

  int max = array[0][0], min = array[0][0];
  int pos_max_x = 0, pos_min_x = 0;
  int pos_max_y = 0, pos_min_y = 0;
  for (int i = 0; i < n; ++i){

    for (int j = 1; j < m; ++j){
      if (array[i][j] < min){
        min = array[i][j];
        pos_min_x = j;
        pos_min_y = i;
      }
      if (array[i][j] > max){
        max = array[i][j];
        pos_max_x = j;
        pos_max_y = i;
      }
    }
  }
  swap(&array[pos_max_y][pos_max_x], &array[pos_min_y][pos_min_x]);

  print_2d_arr(array, n, m);
  return 0;
}

void print_2d_arr(int** array, int n, int m){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k;
}
#endif

#ifdef TEXT_5
void print_2d_arr(int**, int, int);

int main(){
  srand(time(NULL));
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      array[i][j] = rand() % 10;
    }
  }
  print_2d_arr(array, n, m);
  int suma = 0;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      if (i == j)
        suma += array[i][j];
    }
  }
  printf("%d\n", suma);
  return 0;
}

void print_2d_arr(int** array, int n, int m){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
#endif

#ifdef TEXT_6
void print_2d_arr(int**, int, int);
void swap(int*, int*);

int main(){
  srand(time(NULL));
  int n = 0, m = 0;

  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      array[i][j] = rand() % 10;
    }
  }
  print_2d_arr(array, n, m);
  int suma = 0;
  int max_suma = 0, min_suma = n * m * 9;
  int pos_max = 0, pos_min = 0;
  for (int i = 0; i < n; ++i){
    suma = 0;
    for (int j = 0; j < m; ++j){
      suma += array[i][j];
    }
    if (suma < min_suma){
      min_suma = suma;
      pos_min = i;
    }
    if (suma > max_suma){
      max_suma = suma;
      pos_max = i;
    }
  }
  for (int j = 0; j < m; j++){
    swap(&array[pos_min][j], &array[pos_max][j]);
  }
  print_2d_arr(array, n, m);
  for (int i = 0; i < n; i++){
    free(array[i]);
  }
  free(array);
  return 0;
}

void print_2d_arr(int** array, int n, int m){
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k;
}
#endif