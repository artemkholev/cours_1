#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define NAME_BUS 20
#define NAME_STOP 50
#define SIZE_STOP 30

typedef struct Bus{
  char name[NAME_BUS];
  char stop[SIZE_STOP][NAME_STOP];
  int addStop;
}bus;

int findBus(char* str, bus *array, int count);
int findOneStation(bus v1, bus v2);
int findStop(bus *stop, char* nameStop);
void init(bus *element, int len);

int main(){
  int count = 0;
  bus array[10];
  char string[SIZE] = {0};
  FILE * f = fopen("input.txt", "r");
  FILE * o = fopen("output.txt", "w");

  while( fgets(string, SIZE, f) != NULL ){
    char comandOne[20] = {0};
    char comandTwo[20] = {0};
    sscanf(string, "%s", comandOne);

    if ( !strcmp(comandOne, "ADD") ){  // first comand - ADD
      sscanf(string + 4, "%s", comandTwo);
      // Do not save in variable comandTwo
      if (comandTwo[0] == '\0') {
        fprintf(o, "%s%s%s", "WRONG ", comandOne, " FORMAT\n");
        memset(string, 0, SIZE);
        continue;;
      }
      // if enter - BUS
      if ( !strcmp(comandTwo, "BUS") ){
        // save name bus in massive
        char nameBus[NAME_BUS] = {0};
        int flag = 0; //need to understand error
        for (int i = 8; i < SIZE && string[i] != '\n' && string[i] != '\0'; i++) {
          nameBus[i - 8] = string[i];  
          if (string[i] == ' ') { // find error if has
            flag = i;
            break;
          }
        }
        if (flag != 0) { // error will finded
          fprintf(o, "%s%s%s", "WRONG ", comandOne, " FORMAT\n");
          memset(string, 0, SIZE); // clear string for next iteration
          continue;
        }

        if ( findBus(nameBus, array, count) != -1 ) { //find bus in structure
          fprintf(o, "%s%s%s", "BUS ", nameBus, " ALREADY EXISTS\n");
          memset(string, 0, SIZE);
          continue;
        }
        if (count < 10) {
          init(&array[count], SIZE_STOP);
          strcpy(array[count].name, nameBus);
          count++; // increment count on next position
        } else 
          fprintf(o, "%s%s%s", "CAN'T ADD BUS ", nameBus, ". BUSPARK IS FULL\n");
      }

      else if ( !strcmp(comandTwo, "STOP") ) { // if enter - STOP
        char dataStop[NAME_STOP + NAME_BUS] = {0};
        int flag = 0; // check incorrect data
        //save name bus station
        for (int i = 9; i < SIZE && string[i] != '\n' && string[i] != '\0'; i++) {
          dataStop[i - 9] = string[i]; 
          if (string[i] == ' ') 
            flag = i;
        }
        char nameBus[NAME_BUS] = {0};
        char nameStop[NAME_STOP] = {0};
        sscanf(dataStop, "%s%s", nameBus, nameStop);

        if (string[flag + 1] == '\0' || string[flag + 1] == '\n' || nameStop[0] == '\0') {
          fprintf(o, "%s%s%s", "WRONG ", comandOne, " FORMAT\n");
          memset(string, 0, SIZE);
          continue;
        }
        
        int positionBus = findBus(nameBus, array, count);  //find position bus if it has in structure
        if (positionBus == -1) { // if do not find
          fprintf(o, "%s%s%s", "BUS ", nameBus, " DOESN'T EXIST\n");
          memset(string, 0, SIZE);
          continue;
        }
        //if find bus
        int positionStop = findStop(&array[positionBus], nameStop);
        if (positionStop != -1){ 
          fprintf(o, "%s%s%s%s%s", "BUS ", nameBus, " ALREADY HAS STOP ", nameStop, "\n");
        } else {
          if (array[positionBus].addStop == SIZE_STOP) {
            fprintf(o, "%s%s%s%s%s", "CAN'T ADD STOP ", nameStop, " TO BUS ", nameBus, " BUS IS FULL\n");
          } else {
            strcpy(array[positionBus].stop[array[positionBus].addStop], nameStop);
            array[positionBus].addStop++;
          }
        }
      }
    }

    //print 
    else if ( !strcmp(comandOne, "PRINT") ) {
      sscanf(string + 6, "%s", comandTwo);
      if (comandTwo[0] == '\0') {
        fprintf(o, "%s%s%s", "WRONG ", comandOne, " FORMAT\n");
        memset(string, 0, SIZE);
        continue;
      }
      //print bus
      if (!strcmp(comandTwo, "BUS")) {
        char numberBus[NAME_BUS] = {0};
        sscanf(string + 10, "%s", numberBus);
        int posBus = findBus(numberBus, array, count);
        if (posBus == -1) {
          fprintf(o, "%s%s%s", "BUS ", numberBus, " DOESN'T EXIST\n");
          memset(string, 0, SIZE);
          continue;
        }
        fprintf(o, "%s%s", numberBus, "\nSTOPS: ");
        for (int i = 0; i < array[posBus].addStop; i++) 
          fprintf(o, "%s%s", array[posBus].stop[i], " ");
        fprintf(o, "%s", "\n");
      }
      //print stop
       else if ( !strcmp(comandTwo, "STOP") ) {
        char numberStop[NAME_STOP] = {0};
        int flag = 0;
        sscanf(string + 11, "%s", numberStop);
        fprintf(o, "%s%s", numberStop, ": ");
        for (int i = 0; i < count; i++){
          for (int j = 0; j < array[i].addStop; j++){
            if ( !strcmp(array[i].stop[j], numberStop) ) {
              fprintf(o, "%s%s", array[i].name, " ");
              flag = 1;
              break;
            }
          }
        }
        if (flag == 0) {
          fprintf(o, "%s", "NO BUSES GO TO STOP");
        }
        fprintf(o, "%s", "\n");
      }
      //print ALL
      else if ( !strcmp(comandTwo, "ALL") ) {
        //if park empty
        if (count == 0) {
          memset(string, 0, SIZE);
          continue;
        }
        for (int i = 0; i < count; i++) {
          fprintf(o, "%s%s", array[i].name, "\nSTOPS: ");
          for (int j = 0; j < array[i].addStop; j++) {
            fprintf(o, "%s%s", array[i].stop[j] , " ");
          }
          fprintf(o, "%s", "\n");
        }
      }
    }

    //FIND
    else if ( !strcmp(comandOne, "FIND") ) {
      char strOneStation[NAME_STOP] = {0};
      char strTwoStation[NAME_STOP] = {0};
      char strThreeStation[NAME_STOP] = {0};
      sscanf(string + 5, "%s%s%s", strOneStation, strTwoStation, strThreeStation);
      if (strOneStation[0] == '\0' || strTwoStation[0] == '\0' || strThreeStation[0] != '\0') {
        fprintf(o, "%s%s%s", "WRONG ", comandOne, " FORMAT\n");
        memset(string, 0, SIZE);
        continue;
      }
      //if stations equal
      if ( !strcmp(strOneStation, strTwoStation) ) {
        fprintf(o, "%s%s%s", "STOPS ", strOneStation, " ARE THE SAME\n");
        memset(string, 0, SIZE);
        continue;
      }

      //find bus 
      int flag = 0, fp = 0, prIm = 0;
      int **arrayData = (int**)calloc(count, sizeof(int*)); //init massive for find inforamtion about bus
      for (int i = 0; i < count; i++) {
        arrayData[i] = (int*)calloc(2, sizeof(int));
        arrayData[i][0] = -1;
        arrayData[i][1] = -1;
      }
      
      for (int i = 0; i < count; i++) { 
        for (int j = 0; j < array[i].addStop; j++) {
          if ( !strcmp(array[i].stop[j], strOneStation) ) 
            arrayData[i][0] = 1;
          if ( !strcmp(array[i].stop[j], strTwoStation) ) 
            arrayData[i][1] = 1;

          if (arrayData[i][0] == 1 || arrayData[i][1] == 1) {
            if (arrayData[i][0] == 1 && arrayData[i][1] == 1)  // first and secons bus together
              fp = 1;
            flag = 1; // first or second buy with general station
          } 
        }
      }  
      if (flag == 1) {
        if (fp == 1) {
          fprintf(o, "%s%s%s%s%s", "BUSES FROM ", strOneStation, " TO ", strTwoStation, ":\n");
          prIm = 1;
          for (int  i = 0; i < count; i++) 
            if (arrayData[i][0] == 1 && arrayData[i][1] == 1) 
              fprintf(o, "%s%s", array[i].name, "\n");
        } 
        else {
          for (int i = 0; i < count; i++) {
            if (arrayData[i][0] == 1) {
              for (int j = 0; j < count; j++) {
                if (arrayData[j][1] == 1 && findOneStation(array[i], array[j])) {
                  if (prIm++ == 0) 
                    fprintf(o, "%s%s%s%s%s", "BUSES FROM ", strOneStation, " TO ", strTwoStation, ":\n");
                  if (i < j)
                    fprintf(o, "%s%s%s%s", array[i].name, " ", array[j].name, "\n");
                  else
                    fprintf(o, "%s%s%s%s", array[j].name, " ", array[i].name, "\n");
                }
              }
            } 
          }
        }
        if (prIm == 0) {
          fprintf(o, "%s%s%s%s%s", "THERE ARE NO BUSES FROM ", strOneStation, " TO ", strTwoStation, "\n");
        }
        for (int i = 0; i < count; ++i)
          free(arrayData[i]);
        free(arrayData);
        memset(string, 0, SIZE);
        continue;
      }
      //end results
      fprintf(o, "%s%s%s%s%s", "THERE ARE NO BUSES FROM ", strOneStation, " TO ", strTwoStation, "\n");
    }
    memset(string, 0, SIZE);
  }
  fclose(f);
  fclose(o);
  return 0;
}


int findBus(char* str, bus *array, int count) {
  for (int i = 0; i < count; i++) 
    if ( !strcmp(str, array[i].name ) )
      return i;
  return -1;
}

int findStop(bus *stop, char* nameStop) {
  for (int i = 0; i < stop->addStop; i++) 
    if ( !strcmp(stop->stop[i], nameStop) )
      return i;
  return -1;
}

void init(bus *element, int len){
  element->addStop = 0;
  memset(element->name, 0, NAME_BUS);
  for (int i = 0; i < len; i++) 
    memset(element->stop[i], 0, NAME_STOP);
}

int findOneStation(bus v1, bus v2){
  for (int i = 0; i < v1.addStop; i++) {
    for (int j = 0; j < v2.addStop; j++) 
      if ( !strcmp(v1.stop[i], v2.stop[j]) ) 
        return 1;
  }
  return 0;
}