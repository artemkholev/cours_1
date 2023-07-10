#include <stdio.h>

#define size 100
#define size2 10

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
  printf("Expression:\n%s", string);
  pol_not(string, string_dubl);
  printf("\nReverse Polish Notation:\n");
  print_string(string_dubl);
  printf("\nResult:\n");
  printf("%d", answer(string_dubl));
  return 0;
}