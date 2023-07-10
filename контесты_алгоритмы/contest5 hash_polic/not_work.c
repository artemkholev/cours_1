#include <stdio.h>
#include <stdlib.h>

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

int main(){
  int count = 0; 
  char stack[100] = {0};
  char string[100] = {0};
  int stack2[100] = {0};
  char string_dubl[100][10] = {0};
  fgets(string, 100, stdin);
  printf("Expression:\n%s", string);

  int i = 0, j = 0, pom = 0;
  while (string[i] != '\0'){
    if (string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/' && string[i] != '(' && string[i] != ')'){
      pom = 0;
      while (string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/' && string[i] != '(' && string[i] != ')' && string[i] != '\n'){
        string_dubl[j][pom++] = string[i++];
      }
      j++;
    }
    else if (string[i] == '('){
      stack[count++] = string[i];
      i++;
    }
    else if (string[i] == ')'){
      while (stack[--count] != '('){
        string_dubl[j++][0] = stack[count];
        stack[count] = '0';
      }
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
      string_dubl[j++][0] = stack[--count];
  }

  printf("Reverse Polish Notation:\n");
  i = 0;
  while(string_dubl[i][0] != '\0'){
    printf("%s ", string_dubl[i++]);
  }

  printf("\nResult:\n");
  int x = 0;
  i = 0;
  while (string_dubl[i][0] != '\0'){
    if ((string_dubl[i][0] != '+' && string_dubl[i][0] != '-' && string_dubl[i][0] != '*'&& string_dubl[i][0] != '/') || (string_dubl[i][0] == '-' && string_dubl[i][1] != '\0')){
      sscanf(string_dubl[i], "%d", &x);
      stack2[count++] = x;
      i++;
      continue;
    }
    else{
      int n1 = stack2[--count];;
      int n2 = stack2[--count];;
      switch (string_dubl[i][0]){
        case '*':
          stack2[count++] = n1 * n2;
          break;

        case '/':
          stack2[count++] = n2 / n1;
          break;
         
        case '+':
         stack2[count++] = n1 + n2;
          break;

        case '-':
          stack2[count++] = n2 - n1;
          break;
      }
      i++;
    }
  }
  printf("%d", stack2[0]);
  return 0;
}