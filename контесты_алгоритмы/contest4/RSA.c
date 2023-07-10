#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// to create simple numbers
int miller_rabin(long long);
long long pow_bin(long long, long long, long long);
int prime(long long, long long);
long long long_prime_numbers(int);
//pow
long long pow_n(long long , long long);
//Euler function
long long phi(long long);
//create e
//greatest_common_divisor_gsd
long long Euclid(long long, long long);
long long creat_e(long long);
//create d
long long extended_Eiclid(long long*, long long*, long long, long long);
//Encryption
long long  encryption(long long, long long, long long);
long long  unencryption(long long, long long, long long);

int main(){
  // to create simple numbers
  srand(time(NULL));
  long long p = 0, q = 0;
  p = long_prime_numbers(15);
  q = long_prime_numbers(16);
  printf("p - %lld\nq - %lld\n", p, q);
  // create n
  long long n = p * q;
  //Euler function
  //printf("%lld\n", phi(n));
  long long f = (p - 1) * (q - 1);

  long long e = 0;
  long long d = 0, y = 0;
  while (d <= 0){
    //create e
    e = creat_e(f);
    //create d
    d = 0, y = 0;
    long long del = extended_Eiclid(&d, &y, e, f);
  }
  printf("OPEN KEY:   %lld %lld\n", e, n);
  printf("SECURE KEY: %lld %lld\n", d, n);

  long long messege = 0;
  scanf("%lld", &messege);
  messege = encryption(messege, e, n);
  printf("%lld\n", messege);
  messege = unencryption(messege, d, n);
  printf("%lld\n", messege);
  return 0;
}

//prime_numbers
int miller_rabin(long long number){
  srand(time(NULL));
  int n = 25;
  if (number == 1)
    return 0;
  else if (number == 2 || number == 3)
    return 1;

  long long remains = number - 1;
  while (remains % 2 == 0){
    remains /= 2;
  }

  for (int i = 0; i < n; i++){
    if (!prime(remains, number))
      return 0;  
  }
  return 1;
}

int prime(long long remains, long long number){
  long long a = rand() % (number - 4) + 2;
  long long meaning = pow_bin(a, remains, number);
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

long long pow_bin(long long x, long long y, long long n){
  long long answer = 1;
  while (y){
    if (y % 2){
      answer  = (answer * x) % n;
    }
    x = (x * x) % n;
    y /= 2;
  }
  return answer;
}

long long pow_n(long long x, long long y){
  long long answer = 1;
  while (y){
    if (y % 2){
      answer *= x;
    }
    x *= x;
    y /= 2;
  }
  return answer;
}

long long long_prime_numbers(int n){
  long long min_num = pow_n(2, n - 1) - 1;
  long long max_num = pow_n(2, n) + 1;
  long long prime_number = min_num + (rand() % (1 + max_num - min_num));
  while (miller_rabin(prime_number) != 1){
    prime_number = min_num + (rand() % (1 + max_num - min_num));
  }
  return prime_number;
}

//Euler function
//long long phi(long long x){
//   long long number = x;
//   for (int i = 2; i * i <= number; i++){
//     if (x % i == 0){
//       while (x % i == 0){
//         x /= i;
//       }
//       number -= (number / i);
//     }
//   }
//   if (x != 1)
//     number -= number / x;
//   return number;
// }

//create e
long long Euclid(long long a, long long b){
  if (b == 0)
    return a;
  else
    return Euclid(b, a % b);
}
long long creat_e(long long f){
  long long prime_for_f = long_prime_numbers(13);
  while (prime_for_f >= f || Euclid(f, prime_for_f) != 1){
    prime_for_f = long_prime_numbers(13);
  }
  return prime_for_f;
}

//create d
long long extended_Eiclid(long long* x, long long* y, long long  a, long long b){
  if (b == 0){
    *x = 1; 
    *y = 0;
    return a;
  }
  long long x1, y1;
  long long del = extended_Eiclid(&x1, &y1, b, a % b);
  *x = y1; 
  *y = x1 - ((a / b) * y1);
  return del;
}

//Encryption
long long encryption(long long messege, long long e, long long n){
  return pow_bin(messege, e, n);
}

//Unencryption
long long unencryption(long long messege, long long d, long long n){
  return pow_bin(messege, d, n);
}