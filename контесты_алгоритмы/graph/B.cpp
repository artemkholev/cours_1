#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void Breadth_first_search(int start_pos, int f_pos, vector<vector<int>> &array, vector<vector<int>> &board, int y){
  int now_point = 0;
  list<int> point_queue;
  point_queue.push_back(start_pos);
  while (point_queue.empty() == 0){
    now_point = point_queue.front();
    int flag = 0;
    int k1 = now_point / y;
    int k2 = now_point % y;
    if (now_point == f_pos){
      break;
    }
    point_queue.pop_front();
    for (int i = 0; i < array[now_point].size(); i++){
      k1 = array[now_point][i] / y;
      k2 = array[now_point][i] % y;
      if (board[k1][k2] == -1) {
        point_queue.push_back(array[now_point][i]);
        board[k1][k2] = (board[now_point / y][now_point % y] + 1);
      }
    }
  }
}

int main(){
  int x = 0, y = 0;
  int s_x = 0, s_y = 0;
  int f_x = 0, f_y = 0;
  cin >> x >> y;
  vector<int>visited;
  vector<vector<char>> array(x, vector<char>(y));
  vector<vector<int>> graph(x * y);
  vector<vector<int>> path(x, vector<int>(y, -1));
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      cin >> array[i][j];
    }
  }

  
  cout << "Initial labyrinth:" << endl;
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      if (array[i][j] == 'S'){
        s_x = i;
        s_y = j;
      }
      else if (array[i][j] == 'F'){
        f_x = i;
        f_y = j;
      }

      if (array[i][j] == '#')
        graph[i * y + j].push_back(-1);
      else{
        if (i > 0 && array[i - 1][j] != '#')
          graph[i * y + j].push_back(i * y + j - y);
        if (j > 0 && array[i][j - 1] != '#')
          graph[i * y + j].push_back(i * y + j - 1);
        if (j < y - 1 && array[i][j + 1] != '#')
          graph[i * y + j].push_back(i * y + j + 1);
        if (i < x - 1 && array[i + 1][j] != '#')
          graph[i * y + j].push_back(i * y + j + y);
      }
      cout << array[i][j];
    }
    cout << endl;
  }
  cout << "Graph:" << endl;
  for (int i = 0; i < x * y; i++){
    int l = graph[i].size();
    cout << i << " - ";
    if (l){
      for (int j = 0; j < l; j++){
        if (graph[i][j] == -1){
          cout << "None";
          continue;
        }
        cout << graph[i][j] << " ";
      }
    }
    else{
      cout << "None";
    }
    cout << endl;
  }
  cout << "BFS result is:" << endl;
  path[s_x][s_y] = 0;
  Breadth_first_search(s_x * y + s_y, f_x * y + f_y, graph, path, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      cout << path[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}






#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void Breadth_first_search(int start_pos, int f_pos, vector<vector<int>> &array, vector<vector<int>> &board, int y){
  int now_point = 0;
  list<int> point_queue;
  point_queue.push_back(start_pos);
  while (point_queue.empty() == 0){
    now_point = point_queue.front();
    int flag = 0;
    int k1 = now_point / y;
    int k2 = now_point % y;
    if (now_point == f_pos){
      break;
    }
    point_queue.pop_front();
    for (int i = 0; i < array[now_point].size(); i++){
      k1 = array[now_point][i] / y;
      k2 = array[now_point][i] % y;
    
    
      if (board[k1][k2] == -1) {
        point_queue.push_back(array[now_point][i]);
        board[k1][k2] = (board[now_point / y][now_point % y] + 1);
      }
      // if (array[now_point][i] == f_pos){
      //   board[k1][k2] = (board[now_point / y][now_point % y] + 1);
      //   break;
      // }
    }
  }
}

int main(){
  int x = 0, y = 0;
  int s_x = 0, s_y = 0;
  int f_x = 0, f_y = 0;
  cin >> x >> y;
  vector<int>visited;
  vector<vector<char>> array(x, vector<char>(y));
  vector<vector<int>> graph(x * y);
  vector<vector<int>> path(x, vector<int>(y, -1));
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      cin >> array[i][j];
    }
  }

  
  cout << "Initial labyrinth:" << endl;
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      if (array[i][j] == 'S'){
        s_x = i;
        s_y = j;
      }
      else if (array[i][j] == 'F'){
        f_x = i;
        f_y = j;
      }

      if (array[i][j] == '#')
        graph[i * y + j].push_back(-1);
      else{
        if (i > 0 && array[i - 1][j] != '#')
          graph[i * y + j].push_back(i * y + j - y);
        if (j > 0 && array[i][j - 1] != '#')
          graph[i * y + j].push_back(i * y + j - 1);
        if (j < y - 1 && array[i][j + 1] != '#')
          graph[i * y + j].push_back(i * y + j + 1);
        if (i < x - 1 && array[i + 1][j] != '#')
          graph[i * y + j].push_back(i * y + j + y);
      }
      cout << array[i][j];
    }
    cout << endl;
  }
  cout << "Graph:" << endl;
  for (int i = 0; i < x * y; i++){
    int l = graph[i].size();
    cout << i << " - ";
    if (l){
      for (int j = 0; j < l; j++){
        if (graph[i][j] == -1){
          cout << "None";
          continue;
        }
        cout << graph[i][j] << " ";
      }
    }
    else{
      cout << "None";
    }
    cout << endl;
  }
  cout << "BFS result is:" << endl;
  path[s_x][s_y] = 0;
  Breadth_first_search(s_x * y + s_y, f_x * y + f_y, graph, path, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      cout << path[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}










/*
10 9 
F........ 
......... 
.#######. 
.#.....#. 
.#.###.#. 
.#.#S#.#. 
.#.#...#. 
.#.#####. 
.#....... 
.########

10 9 F........ ......... .#######. .#.....#. .#.###.#. .#.#S#.#. .#.#...#. .#.#####. .#....... .########
*/
