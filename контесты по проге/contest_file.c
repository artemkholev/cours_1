#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char array[51][101] = {0};
  int i = 0, j = 0, s_x = 1, s_y = 1, count_prizes = 0;
  int go_right = 1, go_down = 0;
  char k;
  int max = 0;
  FILE * f = fopen("input.txt", "r");
  FILE * o = fopen("output.txt", "w");
  while(fscanf(f, "%c", &k) == 1){
    if (k == '\n'){
      i += 1;
      if (max < j)
        max = j;
      j = 0;
      continue;
    }
    if (k == '*')
      count_prizes++;
    array[i][j++] = k;
  }
  fclose(f);
  i -=2;
  if (j == 0)
    j = max;
  j -= 2;

  while (s_x != i || s_y != j){
    if (array[s_x][s_y] == '*')
      count_prizes--;
    else if (array[s_x][s_y] == '/'){
      if(go_right == 1 && go_down == 0){
        go_down = -1;
        go_right = 0;
      }
      else if (go_right == 0 && go_down == 1){
        go_down = 0;
        go_right = -1;
      }
      else if (go_right == -1 && go_down == 0){
        go_down = 1;
        go_right = 0;
      }
      else if (go_right == 0 && go_down == -1){
        go_down = 0;
        go_right = 1;
      }
    }
    else if (array[s_x][s_y] == '\\'){
      if (go_right == 1 && go_down == 0){
        go_down = 1;
        go_right = 0;
      }
      else if (go_right == 0 && go_down == -1){
        go_down = 0;
        go_right = -1;
      }
      else if (go_right == -1 && go_down == 0){
        go_down = -1;
        go_right = 0;
      }
      else if (go_right == 0 && go_down == 1){
        go_down = 0;
        go_right = 1;
      }
    }
    if(array[s_x + go_down][s_y + go_right] != '#' && array[s_x + go_down][s_y + go_right] != '#'){
      s_x += go_down;
      s_y += go_right;
    }
    else{
      fprintf(o, "%s", "No\n");
      exit(EXIT_SUCCESS);
    }
  }
  if (array[i][j] == '*')
      count_prizes--;
  fprintf(o, "%s", "Yes\n");

  if (!count_prizes)
    fprintf(o, "%s", "Yes\n");
  else  
    fprintf(o, "%s", "No\n");
  return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
//   char array[51][101] = {0};
//   FILE *file; 
//   file = fopen("input.txt", "r");
//   if (file == NULL){
//     printf("Not file in the program.\n");
//     exit(EXIT_SUCCESS);
//   }
//   int i = 0, j = 0;
//   int s_x = 1, s_y = 1;
//   char k;
//   int count_prizes = 0, max = 0;
//   while((k = fgetc(file)) != EOF){
//     if (k == '\n'){
//       i += 1;
//       if (max < j)
//         max = j;
//       j = 0;
//       continue;
//     }
//     if (k == '*')
//       count_prizes++;
//     array[i][j++] = k;
//   }
//   if (j == 0){
//     j = max;
//     i--;
//   }
//   fclose(file);
//   i--;
//   j -= 2;
//   int go_right = 1, go_down = 0;
//   while (s_x != i || s_y != j){
//     if (array[s_x][s_y] == '*')
//       count_prizes--;
//     else if (array[s_x][s_y] == '/'){
//       if(go_right == 1 && go_down == 0){
//         go_down = -1;
//         go_right = 0;
//       }
//       else if (go_right == 0 && go_down == 1){
//         go_down = 0;
//         go_right = -1;
//       }
//       else if (go_right == -1 && go_down == 0){
//         go_down = 1;
//         go_right = 0;
//       }
//       else if (go_right == 0 && go_down == -1){
//         go_down = 0;
//         go_right = 1;
//       }
//     }
//     else if (array[s_x][s_y] == '\\'){
//       if (go_right == 1 && go_down == 0){
//         go_down = 1;
//         go_right = 0;
//       }
//       else if (go_right == 0 && go_down == -1){
//         go_down = 0;
//         go_right = -1;
//       }
//       else if (go_right == -1 && go_down == 0){
//         go_down = -1;
//         go_right = 0;
//       }
//       else if (go_right == 0 && go_down == 1){
//         go_down = 0;
//         go_right = 1;
//       }
//     }
//     if(array[s_x + go_down][s_y + go_right] != '#' && array[s_x + go_down][s_y + go_right] != '#'){
//       s_x += go_down;
//       s_y += go_right;
//     }
//     else{
//       printf("No\n");
//       exit(EXIT_SUCCESS);
//     }
//   }
//   if (array[i][j] == '*')
//       count_prizes--;
//   printf("Yes\n");
//   if (!count_prizes)
//     printf("Yes\n");
//   else  
//     printf("No\n");
//   return 0;
// }