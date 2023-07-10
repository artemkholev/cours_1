#define TEXT
#include <stdio.h>
#include <stdlib.h>

#ifdef TEXT_1
int main(){
  int n = 0, m = 0;
  scanf("%d%d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      scanf("%d", &array[i][j]);
    }
  }

  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      printf("%d ", array[j][i]);
    }
    printf("\n");
  }
  return 0;
}
#endif

#ifdef TEXT_2
void swap(int *, int *);

int main(){
  int n = 0, m = 0;
  scanf("%d%d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      scanf("%d", &array[i][j]);
    }
  }

  int max = -10000000, min = 100000000;
  int pos_max = 0, pos_min = 0;
  for (int i = 0; i < m; i++){
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += array[j][i];
    }
    if (min > sum){
      min = sum;
      pos_min = i;
    }
    if (max < sum){
      max = sum;
      pos_max = i;
    }
    printf("%d ", sum);
  }
  printf("\n");

  for (int i = 0; i < n; i++){
    swap(&array[i][pos_min], &array[i][pos_max]);
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void swap(int *a, int *b){
  int k = *a;
  *a = *b;
  *b = k;
}
#endif

#ifdef TEXT_3
int main(){
  int n = 0;
  scanf("%d", &n);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(n, sizeof(int));
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      scanf("%d", &array[i][j]);
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (array[j][count] == 0 && count < n){
        for (int k = 0; k < n; k++){
          printf("%d ", array[j][k]);
        }
        printf("\n");
        count += 1;
      }
    }
  }
  return 0;
}
#endif

#ifdef TEXT_4
int main(){
  int n = 0, m = 0, sum = 0;
  scanf("%d%d", &n, &m);
  int** array = (int**)calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    array[i] = (int*)calloc(m, sizeof(int));
  }

  int left_x = 0, left_y = 0, right_x = 0, right_y = 0;
  scanf("%d%d%d%d", &left_y, &left_x, &right_y, &right_x);

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      scanf("%d", &array[i][j]);
    }
  }

  for (int i = left_y - 1; i <= right_y - 1; i++){
    for (int j = left_x - 1; j <= right_x - 1; j++){
      sum += array[i][j];
    }
  }
  printf("%d\n", sum);
  return 0;
}
#endif

#ifdef TEXT_5
int check(int**, int, int, int, int);

int main() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int** array2 = (int**)calloc((n + 2), sizeof(int*));
    for (int i = 0; i < n + 2; i++) {
        array2[i] = (int*)calloc((m + 2), sizeof(int));
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            scanf("%d", &array2[i][j]);
        }
    }
    n = n + 2;
    m = m + 2;
    array2[0][0] = array2[n - 2][m - 2];
    array2[0][m - 1] = array2[n - 2][1];
    array2[n - 1][m - 1] = array2[1][1];
    array2[n - 1][0] = array2[1][m - 2];
    for (int j = 1; j < m - 1; j++) {
        array2[0][j] = array2[n - 2][j];
    }
    for (int j = 1; j < m - 1; j++) {
        array2[n - 1][j] = array2[1][j];
    }
    for (int j = 1; j < n - 1; j++) {
        array2[j][0] = array2[j][m - 2];
    }
    for (int j = 1; j < n - 1; j++) {
        array2[j][m - 1] = array2[j][1];
    }

    int flag = 0;
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        flag = 0;
        for (int j = 1; j < m - 1; j++) {
            flag = 0;
            if (check(array2, i, j, n, m) == 0)
                flag = 1;
            if (flag == 0) {
                count += 1;
                printf("%d %d\n", i, j);
            }
        }
    }
    printf("%d\n", count);
    return 0;
}

int check(int** array, int i, int j, int x, int y) {
    if (i > 0 && array[i][j] >= array[i - 1][j])
        return 0;

    if (j > 0 && array[i][j] >= array[i][j - 1])
        return 0;

    if (i < x - 1 && array[i][j] >= array[i + 1][j])
        return 0;

    if (j < y - 1 && array[i][j] >= array[i][j + 1])
        return 0;

    if (j > 0 && i > 0 && array[i][j] >= array[i - 1][j - 1])
        return 0;

    if (i > 0 && j < y - 1 && array[i][j] >= array[i - 1][j + 1])
        return 0;

    if (i < x - 1 && j < y - 1 && array[i][j] >= array[i + 1][j + 1])
        return 0;

    if (i < x - 1 && j > 0 && array[i][j] >= array[i + 1][j - 1])
        return 0;
}
#endif