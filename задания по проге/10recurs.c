#include <stdio.h>
#include <stdlib.h>
#define TEXT

#ifdef TEXT_1
void swap_pos(int n){
  if (n == 0)
    return;
  printf("%2d", n % 10);
  swap_pos(n / 10);
}

int main(){
  int n = 0;
  scanf("%d", &n);
  swap_pos(n);
  return 0;
}
#endif

#ifdef TEXT_2
void swap_pos(int n){
  if (n == 0)
    return;
  swap_pos(n / 10);
  printf("%2d", n % 10);
}

int main(){
  int n = 0;
  scanf("%d", &n);
  swap_pos(n);
  return 0;
}
#endif 

#ifdef TEXT_3
int test(char* str, int s, int f){
  if (str[s] != str[f])
    return 0;
  if (s == f)
    return 1;
  return test(str, ++s, --f);
}

int length(char* str){
  int count = 0;
  while (str[count++] != '\n');
  return --count;
}

int main(){
  char str[10] = {0};
  fgets(str, 10, stdin);
  if (test(str, 0, length(str) - 1))
    printf("Yes");
  else
    printf("No");
  return 0;
}
#endif

#ifdef TEXT_4
int swap_pos(int n, int k){
  if (n == 0)
    return k;
  k = (k * 10 + (n % 10));
  swap_pos(n / 10, k);
}

int main(){
  int n = 0;
  int k = 0;
  scanf("%d", &n);
  n = swap_pos(n, k);
  printf("%d", n);
  return 0;
}
#endif

#ifdef TEXT_5
int miny(int* array, int n){
  if (n == 0)
    return array[0];
  if (array[n] < array[n - 1]){
    int k = array[n];
    array[n] = array[n - 1];
    array[n-1] = k;
  }
  return miny(array, n - 1);
}

int main(){
  int n = 5;
  int* array = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  printf("%d", miny(array, n - 1));
  return 0;
}
#endif

#ifdef TEXT_6
int count(int n, int c){
  if (n == 0)
    return c;
  return count(n / 10, ++c);
}

int main(){
  int n = 0, c = 0;
  scanf("%d", &n);
  printf("%d", count(n, c));
  return 0;
}
#endif

#ifdef TEXT_7
int count(int n){
  if (n == 0)
    return 0;
  return n % 10 + count(n / 10);
}

int main(){
  int n = 0;
  scanf("%d", &n);
  printf("%d", count(n));
  return 0;
}
#endif

#ifdef TEXT_8
int miny(int* array, int n){
  if (n == 0)
    return array[0];
  if (array[n] > 0){
    return array[n] + miny(array, n - 1);
  }
  else
    return miny(array, n - 1);
}

int main(){
  int n = 5;
  int* array = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  printf("%d", miny(array, n - 1));
  return 0;
}
#endif

#ifdef TEXT_9
void miny(int* array, int n){
  if (n < 0)
    return;
  if (n % 2 == 0){
    printf("%d", array[n]);
    return miny(array, n - 1);
  }
  else
    return miny(array, n - 1);
}

int main(){
  int n = 5;
  int* array = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  miny(array, n - 1);
  return 0;
}
#endif

#ifdef TEXT_10
void miny(int* array, int n){
  if (n < 0)
    return;
  if (array[n] % 2 == 0){
    printf("%d", array[n]);
    return miny(array, n - 1);
  }
  else
    return miny(array, n - 1);
}

int main(){
  int n = 5;
  int* array = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++){
    scanf("%d", &array[i]);
  }
  miny(array, n - 1);
  return 0;
}
#endif