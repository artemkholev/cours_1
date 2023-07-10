#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 200
#define NUM 20

typedef struct Train{
  char name[20];
  double timeTo[NUM];
  double timeStart[NUM];
  char station[NUM][30];
  int arrayVisit[NUM];
  int countStation;
}train;

long int dige(char* str, int *i){
  char* end = &str[*i];
  while (*end){
    if (isdigit(str[*i])){
      return ( strtol(end, &end, 10) );
    } else{
      end++;
      (*i)++;
    }
  }
  return 0;
}

int findComand(train *tm, char *comand){
  for (int i = 0; i < tm->countStation; i++){
    if (!strcmp(tm->station[i], comand)){
      return i;
    }
  }
  return -1;
}

void init(train *array){
  array->countStation = 0;
  for (int i = 0; i < NUM; i++){
    array->arrayVisit[i] = 0;
  }

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 20; j++){
      array->station[i][j] = 0;
    }
  }
  for (int i = 0; i < 10; i++){
    array->name[i] = 0;
  }
}

double takeTime(char *time){
  double x = 0, y = 0;
  int i = 0;
  x = (double)dige(time, &i);
  i += 3;
  y = (double)dige(time, &i);
  x += y * 0.01; 
  return x;
}

int findTrainMaxStation(train *array, int count){
  int max = 0, pos = -1;
  int suma = 0, flag = 0;
  for (int i = 0; i < count; i++){
    suma = 0;
    // if (max < array[i].countStation){
    //   max = array[i].countStation;
    //   pos = i;
    // }
    for (int j = 0; j < array[i].countStation; j++){
      suma += array[i].arrayVisit[j];
    }
    if (max < suma){
      flag = 0;
      max = suma;
      pos = i;
    }
    else if (suma == max){
      flag = 1;
    }
  }
  if (flag == 0)
    return pos;
  else 
    return -1;
}

void arrivalTrains(train *array, int count, double time){
  int flag = 0;
  for (int i = 0; i < count; i++){
    for (int j = 0; j < array[i].countStation; j++){
      if (array[i].timeTo[j] <= time){
        flag = 1;
        printf("%s arrival time - %.2lf\n", array[i].name, array[i].timeTo[j]);
      }
    }
  }
  if (flag == 0){
    printf("No train\n");
  }
}

void lessTrain(train *array, int count){
  char stations[NUM][30] = {0};
  int stationsCountV[NUM] = {0};
  int size = 0;
  int p = -1;
  for (int i = 0; i < count; i++){
    for (int j = 0; j < array[i].countStation; j++){
      p = -1;
      for (int k = 0; k < size; k++){
        if ( !strcmp(array[i].station[j], stations[k]) ){
          p = 1;
          stationsCountV[k]++;
        } 
      }
      if (p == -1){
        strcpy(stations[size], array[i].station[j]);
        stationsCountV[size]++;
        size++;
      }
    }
  }
  int min = 1000000;
  for (int i = 0; i < size; i++){
    if (min > stationsCountV[i]){
      min = stationsCountV[i];
    }
  }

  for (int i = 0; i < size; i++){
    if (min == stationsCountV[i]){
      printf("%s - %d\n", stations[i], stationsCountV[i]);
    }
  }
  
}

int main(){
  int count = 0;
  char t1[6] = {0}, t2[6] = {0};
  char string[SIZE] = {0};
  train array[10];
  FILE *file;
  file = fopen("input.txt", "r");

  if (file == NULL){
    printf("Problem with open file\n");
    exit(EXIT_SUCCESS);
  }

  while( fgets(string, SIZE, file) != NULL ){
    char nameTrain[20] = {0};
    char nameStation[30] = {0};
    int flag = 0;
    int posS = 0;
    //sscanf(string, "%s%s%s%s", nameTrain, t1, t2, nameStation);
    for (int i = 0; i < SIZE - 3; i++){
      if (string[i + 3] == ':'){
        for (int j = i + 1; j < SIZE && string[j] != '\0'; j++){
          string[posS] = string[j];
          string[j] = '\0';
          posS++;
        }
        break;
      }
      nameTrain[i] = string[i];
    }
    posS = 0;
    sscanf(string, "%s%s", t1, t2);
    for (int i = 12; i < SIZE && (string[i] != '\0' && string[i] != '\n'); i++){
      nameStation[posS++] = string[i];
    }

    //update last command
    for (int k = 0; k < count; k++){
      if (strcmp(array[k].name, nameTrain) == 0){
        flag = 1;
        int p = findComand(&array[k], nameStation);
        //int p = -1;
        if (p == -1){
          strcpy(array[k].station[array[k].countStation], nameStation);
          p = array[k].countStation++;
        } 
        array[k].arrayVisit[array[k].countStation - 1]++;
        array[k].timeStart[p] = takeTime(t2);
        array[k].timeTo[p] = takeTime(t1);
      }
    }

    //Add new
    if (flag == 0){
      init(&array[count]);
      strcpy(array[count].name, nameTrain);
      array[count].timeTo[array[count].countStation] = takeTime(t1);
      array[count].timeStart[array[count].countStation] = takeTime(t2);
      strcpy(array[count].station[array[count].countStation], nameStation);
      array[count].arrayVisit[array[count].countStation]++;
      array[count].countStation++;
      count++;
    }
  }
  fclose(file);

  int posMaxStation = findTrainMaxStation(array, count);
  char timeArivT[6] = {0};
  double timeEnter = 0;
  printf("---------------------------------------------------------------------\n");
  if (posMaxStation == -1){
     printf("Output of the train with the maximum number of stations visited: None\n");
  } else
    printf("Output of the train with the maximum number of stations visited: %s\n", array[posMaxStation].name);
  printf("---------------------------------------------------------------------\n");
  printf("Enter time to arrival to the trains: ");
  scanf("%s", timeArivT);
  timeEnter = takeTime(timeArivT);
  printf("\nArrival to the trains:\n");
  arrivalTrains(array, count, timeEnter);
  printf("---------------------------------------------------------------------\n");
  printf("A station where there are fewer trains\n");
  lessTrain(array, count);
  printf("---------------------------------------------------------------------\n");
  return 0;
}