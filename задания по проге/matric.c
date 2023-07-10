#define TEXT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef TEXT_1
  void do_array(int**, int, int);
  void print_array(int**, int, int);

  int main(){
    int n = 0, m = 0;
    srand(time(NULL));
    scanf("%d %d", &n, &m);
    int** array = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++){
      array[i] = (int*)calloc(m, sizeof(int));
    }
    do_array(array, n, m);
    print_array(array, n, m);
    for (int i = 0; i < n; i++){
      int min_j = 10, pos_j = 0;
      int max_i = -10, pos_i = -1;
      for (int j = 0; j < m; j++){
        if (min_j > array[i][j]){
          min_j = array[i][j];
          pos_j = j;
        }
      }
      for (int k = 0; k < n; k++){
        if (max_i < array[k][pos_j]){
          max_i = array[k][pos_j];
          pos_i = k;
        }
      }
      if (i == pos_i)
        printf("%d | %d %d\n", min_j, i + 1, pos_j + 1);
    }
  }

  void do_array(int** array, int n, int m){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        array[i][j] = rand() % 10;
      }
    }
  }

  void print_array(int** array, int n, int m){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        printf("%d ", array[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
#endif

#ifdef TEXT_2
void do_array(int**, int, int);
void print_array(int**, int, int);

int main(){
  int n = 0, m = 0;
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }
  do_array(array, n, m);
  print_array(array, n, m);
  int pos_max1 = 0, pos_max2 = 0, max = -1e03, suma = 0; 
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      for (int k = 0; k < m; k++){
        suma += (array[i][k] * array[j][k]);
      }
      if (max < suma){
        max = suma;
        pos_max1 = i;
        pos_max2 = j;
      }
    }
  }
  printf("%d %d", pos_max1 + 1, pos_max2 + 1);
}

void do_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      array[i][j] = rand() % 10;
    }
  }
}

void print_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
#endif

#ifdef TEXT_3
void do_array(int**, int, int);
void print_array(int**, int, int);

int main(){
  int n = 0, m = 0;
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }
  do_array(array, n, m);
  print_array(array, n, m);
  int pos_max1 = 0, pos_max2 = 0, suma = 0; 
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      for (int k = 0; k < m; k++){
        suma += (array[i][k] * array[j][k]);
      }
      if (suma == 0){
        printf("%d %d\n", i, j);
      }
    }
  }
  return 0;
}

void do_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      array[i][j] = rand() % 10;
    }
  }
}

void print_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
#endif

#ifdef TEXT_4
void do_array(int**, int, int);
void print_array(int**, int, int);

int main(){
  int n = 0, m = 0;
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }
  do_array(array, n, m);
  print_array(array, n, m);
  double suma = 0; 
  int flag = 0;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      flag = 0;
      suma = (array[i][0] * 1.0) / array[j][0] * 1.0; 
      for (int k = 1; k < m; k++){
        if (suma != (array[i][k] * 1.0) / array[j][k] * 1.0){
          flag = 1;
          break;
        }
      }
      if (flag == 0)
        printf("%d %d\n", i + 1, j + 1);
    }
  }
  return 0;
}

void do_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      array[i][j] = rand() % 10;
      //scanf("%d", &array[i][j]);
    }
  }
}

void print_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
#endif

#ifdef TEXT_5

#endif

#ifdef TEXT_6
void do_array(int**, int, int);
void print_array(int**, int, int);

int main(){
  int n = 0, m = 0;
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }
  do_array(array, n, m);
  print_array(array, n, m);
  int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (i < n / 2 && j < m - i - 1 && j > i)
        sum1 += array[i][j];
      else if (j > m - 1 - m / 2 && j > m - i - 1 && j > i)
        sum2 += array[i][j];
      else if (i > n - 1 - n / 2 && j > m - i - 1 && j < i)
        sum3 += array[i][j];
      else if (j < m / 2 && j < m - i - 1 && j < i)
        sum4 += array[i][j];
    }
  }
  printf("%d %d %d %d\n", sum1, sum2, sum3, sum4);
  return 0;
}

void do_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      array[i][j] = rand() % 10;
      //scanf("%d", &array[i][j]);
    }
  }
}

void print_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
#endif

#ifdef TEXT_7
void do_array(int**, int, int);
void print_array(int**, int, int);
void swap(int*, int*);

int main(){
  int n = 0, m = 0, k = 0;
  srand(time(NULL));
  scanf("%d %d %d", &n, &m, &k);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  k = k % 4;
  do_array(array, n, m);
  print_array(array, n, m);
  while (k != 0){
    for (int i = 0; i < n / 2; i++){
      for (int j = i + 1; j < (m - i - 1) && j > i; j++){
        swap(&array[i][m - 1 - j], &array[n - 1 -j][m - 1 - i]);
      }
    }
    for (int i = 0; i < n / 2; i++){
      for (int j = i + 1; j < m - i - 1 && j > i; j++){
        swap(&array[i][j], &array[n - 1 - i][m - 1 - j]);
      }
    }
    for (int i = 0; i < n / 2; i++){
      for (int j = i + 1; j < m - i - 1 && j > i; j++){
        swap(&array[i][j], &array[n - 1 -j][i]);
      }
    }
    k -= 1;
  }
  print_array(array, n, m);
  return 0;
}

void do_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      array[i][j] = rand() % 10;
      //scanf("%d", &array[i][j]);
    }
  }
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k;
}

void print_array(int** array, int n, int m){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
#endif