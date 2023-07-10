#include <stdio.h>
#include <string.h>

#define LEN 200
#define NUMBER 10
#define PARAMETRS 4

typedef struct {
    char name[LEN];
    char enemy[NUMBER][NUMBER*2];
    int score[NUMBER][PARAMETRS];
    int position;
} Team;

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    int k = 0;
    Team teams[LEN];

    while (!feof(input_file)) {
        char team1_name[20], team2_name[20];
        int team1_goals, team2_goals;
        fscanf(input_file, "%[^ ] - %[^ ] %d:%d\n", team1_name, team2_name, &team1_goals, &team2_goals);

        int first = 0, second = 0;
        for(int i = 0; i < k; i++){
            if(strcmp(teams[i].name, team1_name) == 0){
                first = 1;
                int result = 0;
                for(int j = 0; j < teams[i].position; i++){
                    if(!strcmp(teams[i].enemy[j], team2_name)){
                        result = j;
                        break;
                    }
                    else{
                        result = -1;
                    }
                }
               if(result == -1){
                   strcpy(teams[i].enemy[teams[i].position], team2_name);
                   result = teams[i].position;
                   teams[i].position++;
               }
               teams[i].score[result][0]++;
               if(team1_goals > team2_goals){
                   teams[i].score[result][2]++;
               }
               teams[i].score[result][3] += team1_goals;
            }
            else if(strcmp(teams[i].name, team2_name) == 0){
                second = 1;
                int result = 0;
                for(int j = 0; j < teams[i].position; i++){
                    if(!strcmp(teams[i].enemy[j], team1_name)){
                        result = j;
                        break;
                    }
                    else{
                        result = -1;
                    }
                }
                if(result == -1){
                    strcpy(teams[i].enemy[teams[i].position], team1_name);
                    result = teams[i].position;
                    teams[i].position++;
                }
                teams[i].score[result][0]++;
                teams[i].score[result][1]++;
                if(team1_goals < team2_goals){
                    teams[i].score[result][2]++;
                }
                teams[i].score[result][3] += team2_goals;
            }
        }

        if(first == 0){
            teams[k].position = 0;
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 4; j++){
                    teams[k].score[i][j] = 0;
                }
            }
            strcpy(teams[k].name, team1_name);
            strcpy(teams[k].enemy[teams[k].position], team2_name);
            int rate = teams[k].position++;
            teams[k].score[rate][0]++;
            if(team1_goals > team2_goals){
                teams[k].score[rate][2]++;
            }
            teams[k].score[rate][3] += team1_goals;
            k++;
        }
        if(second == 0){
            teams[k].position = 0;
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 4; j++){
                    teams[k].score[i][j] = 0;
                }
            }
            strcpy(teams[k].name, team2_name);
            strcpy(teams[k].enemy[teams[k].position], team1_name);
            int rate = teams[k].position++;
            teams[k].score[rate][0]++;
            teams[k].score[rate][1]++;
            if(team1_goals < team2_goals){
                teams[k].score[rate][2]++;
            }
            teams[k].score[rate][3] += team2_goals;
            k++;
        }
    }

    for(int i = 0; i < k; i++){
        fprintf(output_file,"%s\n", teams[i].name);
        for(int j = 0; j < teams[i].position;j++){
            fprintf(output_file, "%s %d %d %d %d\n", teams[i].enemy[j], teams[i].score[j][0], teams[i].score[j][1],teams[i].score[j][2],teams[i].score[j][3]);
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}

