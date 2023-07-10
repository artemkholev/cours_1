#define TEXT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//решето эратосфена
#ifdef sive_eratosphenus
//it is sive Eratosphenus
int main(){
  int n = 21;
  int* array = (int*)calloc(n, sizeof(int));
  for (int i = 2; i*i < n; ++i){
    if (array[i] == 0){
      for (int j = i*i; j < n; j += i){
        array[j] = 1;
      }
    }
  }

  for (int i = 0; i < n; ++i){
    printf("%3d", i);
  }

  printf("\n");
  for (int i = 1; i < n; ++i){
    if (array[i] == 0)
      printf("%3d", i);
  }
  printf("\n");
  return 0;
}
#endif

#ifdef sisve2
void sive_eratosphenus(int*, int);
void print_array(int*, int);

int main(){
  int n = 0;
  scanf("%d", &n);
  int* array = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++){
    array[i] = 1;
  } 
  sive_eratosphenus(&array[0], n);
  return 0;
}

void print_array(int* array, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void sive_eratosphenus(int* array, int n){
  array[1] = 0;
  for (int i = 2; i*i < n; i++){
    if (array[i] == 1){
      for (int j = i*i; j < n; j += i){
        array[j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++){
    if (array[i] == 1)
      printf("%d ", i);
    else 
      printf("0 ");
  }
  printf("\n");
  print_array(array, n);
}
#endif

//бинарный поиск
#ifdef bin_search
void quick_sort(int*, int, int);
void do_array(int*, int);
void print_array(int*, int);
int quick(int*, int, int);
void swap(int*, int*);
bool bin_search(int*, int, int, int);

int main(){
  srand(time(NULL));
  int n = 0, pos = 0;
  scanf("%d", &n);
  int* array = (int*)calloc(n, sizeof(int));
  do_array(&array[0], n);
  print_array(&array[0], n);
  quick_sort(&array[0], 0, n - 1);
  print_array(&array[0], n);
  scanf("%d", &pos);
  bool answer = bin_search(&array[0], pos, 0, n - 1);
  if (answer)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}

bool bin_search(int* array, int pos, int left, int right){
  int middle = (left + right) / 2;
  if (pos == array[middle])
    return true;
  else if (left >= right)
    return false;
  if (pos > array[middle])
    bin_search(array, pos, middle + 1, right);
  else
    bin_search(array, pos, left, middle - 1);
}

void swap(int* a, int* b){
  int k = *a;
  *a = *b;
  *b = k;
}

void quick_sort(int* array, int left, int right){
  if (left >= right)
    return;
  int patition = quick(array, left, right);
  quick_sort(array, left, patition - 1);
  quick_sort(array, patition + 1, right);
}

int quick(int* array, int left, int right){
  int pivot_index = left + (rand() % (right - left));
  if (right != pivot_index){
    swap(&array[pivot_index], &array[right]);
  }
  int pivot_value = array[right];

  int ind = left;
  for (int i = left; i < right; i++){
    if (array[i] <= pivot_value){
      swap(&array[i], &array[ind]);
      ind += 1;
    }
  }
  swap(&array[ind], &array[right]);
  return ind;
}

void do_array(int *array, int n){
  for (int i = 0; i < n; ++i){
    array[i] = rand() % 100 - 20;
  }
}

void print_array(int* array, int n){
  for (int i = 0; i < n; ++i){
    printf("%3d", array[i]);
  }
  printf("\n");
}
#endif

//возведение числа в степень по модулю
#ifdef MosExp
//возведение в степень по модулю
int MosExp(int, int, int);

int main(){
  int x = 0, y = 0, n = 0;
  int all = 0;
  scanf("%d%d%d", &x, &y, &n);
  all = MosExp(x, y, n);
  printf("%d \n", all);
  return 0;
}

int MosExp(int x, int y, int n){
  if (y == 0)
    return 1;
  int z = MosExp(x, y / 2, n);
  if (y % 2 == 0)
    return ((z *z) % n);
  else
    return ((x * z * z) % n);
}

#endif

//наибольший общий делитель
#ifdef greatest_common_divisor_gsd
//наибольший общий делитель
int Euclid(int, int);

int main(){
  int a = 0, b = 0;
  scanf("%d %d", &a, &b);
  printf("%d\n", Euclid(a, b));
  return 0;
}

int Euclid(int a, int b){
  if (b == 0)
    return a;
  return Euclid(b, a % b);
}

// int extended_Eiclid(int*, int*, int, int);

// int main(){
//   int x = 0, y = 0, a = 0, b = 0;
//   scanf("%d %d", &a, &b);
//   int del = extended_Eiclid(&x, &y, a, b);
//   printf("x - %d, y - %d, %d\n", x, y, del);
//   return 0;
// }

// int extended_Eiclid(int* x, int* y, int a, int b){
//   if (b == 0){
//     *x = 1; 
//     *y = 0;
//     return a;
//   }

//   int x1, y1;
//   int del = extended_Eiclid(&x1, &y1, b, a % b);
//   *x = y1; 
//   *y = x1 - ((a / b) * y1);

//   return del;
// }
#endif

//наибольшее общее кратное
#ifdef least_common_multiply
int nok(int, int);
int gcd(int, int);

int main(){
  int a = 0, b = 0;
  scanf("%d %d", &a, &b);
  printf("%d\n", nok(a, b));
  return 0;
}

int gcd(int a, int b){
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int nok(int a, int b){
  return abs(a * b) / gcd(a, b);
}
#endif 

//определение простого числа перебором
#ifdef prime
int prime(int);

int main(){
  int n = 0;
  scanf("%d", &n);
  if (prime(n))
    printf("Yes\n");
  else 
    printf("No\n");
  return 0;
}

int prime(int n){
  if (n == 1 || n == 2){
    return 1;
  }
  for (int i = 2; i*i <= n; i++){
    if (n % i == 0){
      return 0;
    }
  }
}
#endif

//возведение в степень
#ifdef bin_pow
int pow_b(int, int);

int main(){
  int x = 0, y = 0;
  scanf("%d %d", &x, &y);
  printf("%d\n", pow_b(x, y));
  return 0;
}

int pow_b(int x, int y){
  int answer = 1;
  while (y){
    if (y % 2){
      answer *= x;
    }
    x *= x;
    y /= 2;
  }
  return answer;
}
#endif

//возведение в степень по модулю
#ifdef bin_pow_mod
int pow_b(int, int, int);

int main(){
  int x = 0, y = 0, m = 0;
  scanf("%d %d %d", &x, &y, &m);
  printf("%d\n", pow_b(x, y, m));
  return 0;
}

int pow_b(int x, int y, int m){
  int answer = 1;
  while (y){
    if (y % 2){
      answer = (answer * x) %m;
    }
    x = (x * x) % m;
    y /= 2;
  }
  return answer;
}
#endif

//проверка на простоту тетст Ферма
#ifdef test_ferma
int test_ferma(int);
int pow_b_m(int, int, int);

int main(){
  int x = 0;
  scanf("%d", &x);
  if (test_ferma(x))
    printf("Yes\n");
  else
    printf("No");
  return 0;
}

int test_ferma(int x){
  srand(time(NULL));
  int meaning = 15;
  if (x == 1)
    return 0;
  if (x == 2 || x == 3)
    return 1;
  for (int i = 0; i < meaning; i++){
    int a = rand() % (x - 1) + 1;
    if (pow_b_m(a, x - 1, x) != 1)
      return 0;
  }
  return 1;
}
int pow_b_m(int x, int y, int m){
  int answer = 1;
  while (y){
    if (y % 2){
      answer = (answer * x) % m;
    }
    x = (x*x) % m;
    y /= 2;
  }
  return answer;
}
#endif

//Miller Rabin test
#ifdef Miller_Rabin_test
int miller_rabin(int);
int pow_bin(int, int, int);
int prime(int, int);

int main(){
  int x = 0;
  scanf("%d", &x);
  if (miller_rabin(x) == 1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}

int miller_rabin(int number){
  srand(time(NULL));
  int n = 15;
  if (number == 1)
    return 0;
  else if (number == 2 || number == 3)
    return 1;

  int remains = number - 1;
  while (remains % 2 == 0){
    remains /= 2;
  }

  for (int i = 0; i < n; i++){
    if (!prime(remains, number))
      return 0;  
  }
  return 1;
}

int prime(int remains, int number){
  int a = rand() % (number - 4) + 2;
  int meaning = pow_bin(a, remains, number);
  if (meaning == 1 || meaning == number - 1)
    return 1;
  while (remains < number){
    meaning = (meaning * meaning) % number;
    if (meaning == 1)
      return 0;
    if (meaning == number - 1)
      return 1;
    remains *= 2;
  }
  return 0;
}

int pow_bin(int x, int y, int n){
  int answer = 1;
  while (y){
    if (y % 2){
      answer  = (answer * x) % n;
    }
    x = (x * x) % n;
    y /= 2;
  }
  return answer;
}
#endif

//function Eilera
#ifdef function_Eilera
int phi(int);

int main(){
  int x = 0;
  scanf("%d", &x);
  printf("%d", phi(x));
  return 0;
}

int phi(int x){
  int number = x;
  for (int i = 2; i * i <= number; i++){
    if (x % i == 0){
      while (x % i == 0){
        x /= i;
      }
      number -= (number / i);
    }
  }
  if (x != 1)
    number -= number / x;
  return number;
}
#endif

#ifdef TEXT_1
int miller_rabin(int);
int pow_bin(int, int, int);
int prime(int, int);

int main(){
  int count = 0;
  printf("!!!\n");
  for (int i = 2; i < 100000; i++){
    if (miller_rabin(i) == 1)
      count++;
  }
  printf("%d\n", count);
  return 0;
}

int miller_rabin(int number){
  srand(time(NULL));
  int n = 25;
  if (number == 1 || number == 4)
    return 0;
  else if (number == 2 || number == 3)
    return 1;

  int remains = number - 1;
  while (remains % 2 == 0){
    remains /= 2;
  }

  for (int i = 0; i < n; i++){
    if (!prime(remains, number))
      return 0;  
  }
  return 1;
}

int prime(int remains, int number){
  int a = (rand() % (number - 4)) + 2;
  int meaning = pow_bin(a, remains, number);
  if (meaning == 1 || meaning == number - 1)
    return 1;
  while (remains < number){
    meaning = (meaning * meaning) % number;
    if (meaning == 1)
      return 0;
    if (meaning == number - 1)
      return 1;
    remains *= 2;
  }
  return 0;
}

int pow_bin(int x, int y, int n){
  int answer = 1;
  while (y){
    if (y % 2){
      answer  = (answer * x) % n;
    }
    x = (x * x) % n;
    y /= 2;
  }
  return answer;
}
#endif