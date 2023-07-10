#define TEXT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef TEXT_1
int miller(int, int*, int*);
int fermat(int);
int pow_b(int, int, int);
int Euclid(int, int);

int main(){
  int x = 0;
  scanf("%d", &x);
  int count1 = 0, count2 = 0;
  int p = miller(x, &count1, &count2);
  printf("Miller-Rabin test: ");
  if (count1 + count1 > x - count1 - count2 - 1)
    printf("True %d %d %d\n", x - count1 - count2 - 1, count1, count2);
  else
    printf("False %d %d %d\n", x - count1 - count2 - 1, count1, count2);

  count1 = 0, count2 = 0;
  count1 = fermat(x);
  printf("Fermat test: ");
  if (count1 < x - count1 - 1)
    printf("True %d %d\n", count1, x - count1 - 1);
  else
    printf("False %d %d\n", count1, x - count1 - 1);
  return 0;
}

int miller(int x, int* count1, int* count2){
  int r = x - 1;
  int s = 0;
  while (r % 2 == 0){
    s += 1;
    r /= 2;
  }
  for (int i = 1; i < x; i++){
    int m = pow_b(i, r, x);
    if (m == 1){
      *count1 += 1;
      continue;
    }
    if (m == x - 1){
      *count2 += 1;
      continue;
    }
    for (int j = 0; j < s; j++){
      m = (m * m) % x;
      if (m == 1){
        continue;
      }
      if (m == x - 1){
        *count2 += 1;
        continue;
      }
    }
  }
  return 1;
}

int fermat(int number){
  int count = 0;
  for (int i = 1; i < number; i++){
    if (Euclid(number, i) != 1){
      count += 1;
      continue;
    }
    if (pow_b(i, number - 1, number) != 1)
      count += 1;
  }
  return count;
}

int pow_b(int x, int y, int n){
  int answer = 1;
  while (y){
    if (y % 2){
      answer = (answer * x) % n;
    }
    x = (x * x) % n;
    y /= 2;
  }
  return answer;
}

int Euclid(int a, int b){
  if (b == 0)
    return a;
  return Euclid(b, a % b);
}
#endif

#ifdef TEXT_2
void sive_eratosphenus(int*, int, int);

int main(){
  int s = 0 , f = 0;
  scanf("%d %d", &s, &f);
  printf("Start and finish: %d %d\n", s, f);
  int* array = (int*)calloc(f + 1, sizeof(int));
  for (int i = 0; i <= f; i++){
    array[i] = 1;
  } 
  sive_eratosphenus(&array[0], s, f);
  return 0;
}

void sive_eratosphenus(int* array, int s, int f){
  array[1] = 0;
  int count = 0;
  for (int i = 2; i*i <= f; i++){
    int m = 0;
    if (array[i] == 1){
      count += 1;
      for (int j = i*i; j <= f; j += i){;
        if (m == 0 && j >= s && array[j] != 0){
          printf("Iteration : %d\n", count);
          m = 1;
          //count += 1;
        }
        if (j >= s && array[j] != 0){
          printf("%d ", j);
          m = 2;
        }
        array[j] = 0;
      }
      if (m == 2)
        printf("\n");
    }
  }
  int flag = 0;
  printf("Primes :\n");
  for (int i = s; i <= f; i++){
    if (array[i] == 1){
      printf("%d ", i);
      flag = 1;
    }
  }
  if (flag == 0)
    printf("No primes");
}
#endif


