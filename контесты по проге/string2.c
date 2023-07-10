#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 

#define TEXT

#ifdef TEXT_1
int main(){
  char str[10000] = {0};
  char simbol;
  int count = 0;
  fgets(str, 10000, stdin);
  for (int i = 0; str[i] != '\n'; i++){
    if (i % 2 != 0){
      simbol = str[i - count];
      int j = i - count;
      while (str[j] != '\n'){
        str[j] = str[j+1];
        j++;
      }
      str[j-1] = simbol;
      count++;
    }
  }
  printf("%s", str);
  return 0;
}
#endif 

#ifdef TEXT_2
int length(char* str){
  int count = 0;
  while (str[count++] != '\n');
  return --count;
}

int main(){
  char str[10000] = {0};
  char simbol;
  fgets(str, 10000, stdin);
  int count = length(str);
  for (int i = 0; str[i] != '\n' && i != count;){
    if ((int)str[i] >= 48 && (int)str[i] <= 57){
      simbol = str[i];
      int j = i;
      while (str[j] != '\n'){
        str[j] = str[j+1];
        j++;
      }
      str[j-1] = simbol;
      count--;
    }
    if ((int)str[i] < 48 || (int)str[i] > 57)
      i++;
  }
  printf("%s", str);
  return 0;
}
#endif

#ifdef TEXT_3
int test(char* str, int s, int f){
  while (str[s] == ' ' && str[s] != '\n')
    s++;
  while (str[f] == ' ' && f >= 0)
    f--;

  if (str[s] != str[f])
    return 0;
  //if (s == f)
  //  return 1;
  if (f <= s)
    return 1;
  return test(str, ++s, --f);
}

int length(char* str){
  int count = 0;
  while (str[count++] != '\n');
  return --count;
}

int main(){
  char str[100] = {0};
  fgets(str, 100, stdin);
  if (test(str, 0, length(str) - 1))
    printf("yes");
  else
    printf("no");
  return 0;
}

//  abb a abba   
//__abb_a_abba___
#endif

#ifdef TEXT_4
void l(char *str, int *i){
  while ((int)str[*i] >= 48 && (int)str[*i] <= 57)
    (*i)++;
  while ((int)str[*i] < 48 && (int)str[*i] > 57){
    (*i)++;
  }
}

int dige(char* str, int *i){
  char* end = &str[*i];
  while (*end){
    if (isdigit(str[*i])){
      return strtol(end, &end, 10);
    }
    else{
      end++;
      (*i)++;
    }
  }
}

int main(){
  char str[100] = {0};
  char comand_1[12] = {0};
  char comand_2[12] = {0};
  fgets(str, 100,stdin);

  int i = 0, j = 0;
  while (str[i] != ' '){
    comand_1[i] = str[i];
    i++;
  }
  i += 3;
  while (str[i] != ' '){
    comand_2[j] = str[i];
    i++;
    j++;
  }
  i++;
  long x2 = dige(str, &i);
  l(str, &i);
  long y2 = dige(str, &i);
  l(str, &i);
  long x1 = dige(str, &i);
  l(str, &i);
  long y1 = dige(str, &i);

  int r1 = 0, r2 = 0, r3 = 0;
  if (x1 > y1)
    r1 = 1;
    //printf("%s\n", comand_1);
  else if (x1 < y1)
    r1 = 2;
    //printf("%s\n", comand_2);
  else 
    r1 = 0;
    //printf("draw\n");
//---------------------------------
  if ((x2 - x1) > (y2 - y1))
    r2 = 1;
    //printf("%s\n", comand_1);
  else if ((x2 - x1) < (y2 - y1))
    r2 = 2;
    //printf("%s\n", comand_2);
  else 
    r2 = 0;
    //printf("draw\n");
//---------------------------------
  if (x2 > y2)
    r3 = 1;
    //printf("%s\n", comand_1);
  else if (x2 < y2)
    r3 = 2;
    //printf("%s\n", comand_2);
  else 
    r3 = 0;
    //printf("draw\n");

  if (r1 == r2 && r1 == r3){
    if (r1 == 1){
      printf("%s\n", comand_1);
    }
    else if (r1 == 2){
      printf("%s\n", comand_2);
    }
    else{
      printf("draw\n");
    }
  }
  else{
    if (r1 == 1)
      printf("%s\n", comand_1);
    else if (r1 == 2)
      printf("%s\n", comand_2);
    else
      printf("draw\n");

    if (r2 == 1)
      printf("%s\n", comand_1);
    else if (r2 == 2)
      printf("%s\n", comand_2);
    else
      printf("draw\n");
    
    if (r3 == 1)
      printf("%s\n", comand_1);
    else if (r3 == 2)
      printf("%s\n", comand_2);
    else
      printf("draw\n");
  }
  return 0;
}
#endif 
//Manchester - Liverpool 4:4 (3:4)
//Manchester - Liverpool 123:123 (123:123)
#ifdef TEXT
#define size 1000
#define size2 1000

int count = 0; 
char stack[size] = {0};

void print_string(char string_dubl[size][size2]){
  int i = 0;
  while(string_dubl[i][0] != '\0'){
    printf("%s ", string_dubl[i++]);
  }
}

void push(char value){
  stack[count++] = value;
}

void push_n(int* stack2, int value){
  stack2[count++] = value;
}

char pop(){
  char k = stack[--count];
  stack[count] = '0';
  return k;
}

int pop_n(int* stack2){
  int k = stack2[--count];
  return k;
}

void pop_same(char string_dubl[size][size2], int* j){
  int k = *j;
  while (stack[--count] != '('){
    string_dubl[k++][0] = stack[count];
    stack[count] = '0';
  }
  *j = k;
}

int level(char a){
  if (a == '+' || a == '-')
    return 1;
  else if (a == '*' || a == '/')
    return 2;
  else if (a == '(')
    return 1;
  else
    return 0;
}

void pol_not(char* string, char string_dubl[size][size2]){
  int i = 0, j = 0, pom = 0;
  while (string[i] != '\0'){
    if (string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/' && string[i] != '(' && string[i] != ')'){
      pom = 0;
      while (string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/' && string[i] != '(' && string[i] != ')' && string[i] != '\0'){
        string_dubl[j][pom++] = string[i++];
      }
      j++;
    }
    else if (string[i] == '('){
      push('(');
      i++;
    }
    else if (string[i] == ')'){
      pop_same(string_dubl, &j);
      i++;
    }
    else if (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/'){
      while (level(string[i]) <= level(stack[count - 1]) && stack[count - 1] != '('){
        if (stack[count - 1] != '0'){
          string_dubl[j++][0] = stack[--count];
          stack[count] = '0';
        }
      }
      stack[count++] = string[i++];
    }
  }
  if (count != 0){
    while (count != 0)
      string_dubl[j++][0] = pop();
  }
}

int answer(char string[size][size2]){
  int array[size] = {0};
  int x = 0;
  int i = 0;
  while (string[i][0] != '\0'){
    if ((string[i][0] != '+' && string[i][0] != '-' && string[i][0] != '*'&& string[i][0] != '/') || (string[i][0] == '-' && string[i][1] != '\0')){
      sscanf(string[i], "%d", &x);
      push_n(array, x);
      i++;
      continue;
    }
    else{
      int n1 = pop_n(array);
      int n2 = pop_n(array);
      switch (string[i][0]){
        case '*':
          push_n(array, n1 * n2);
          break;

        case '/':
          push_n(array, n2 / n1);
          break;
         
        case '+':
          push_n(array, n1 + n2);
          break;

        case '-':
          push_n(array, n2 - n1);
          break;
      }
      i++;
    }
  }
  return array[0];
}

int main(){
  char string[size] = {0};
  char string_dubl[size][size2] = {0};
  fgets(string, size, stdin);
  pol_not(string, string_dubl);
  printf("%d", answer(string_dubl));
  return 0;
}
#endif