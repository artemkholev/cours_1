#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef struct Graph{
  vector<pair<int, int>> path;
} graph;


void Breadth_first_search(int start_pos, int f_pos, vector<graph> &gr, vector<vector<int>> &board, int y){
  int max = 10000, nowPoint;
  list<int> point_queue;
  point_queue.push_back(start_pos);
  while (point_queue.empty() == 0){ 
    nowPoint = point_queue.front();
    int k = board[nowPoint / y][nowPoint % y];
    while (k > max){
      point_queue.push_back(nowPoint);
      point_queue.pop_front();
      nowPoint = point_queue.front();
      k = board[nowPoint / y][nowPoint % y];
    }
   
    int k1 = nowPoint / y;
    int k2 = nowPoint % y;
    if (nowPoint == f_pos)
      break;

    point_queue.pop_front();
    max = 10000;
    for (int i = 0; i < gr[nowPoint].path.size(); i++){
      k1 = gr[nowPoint].path[i].first / y;
      k2 = gr[nowPoint].path[i].first % y;
      if (board[k1][k2] == -1) {
        point_queue.push_back(gr[nowPoint].path[i].first);
        board[k1][k2] = (board[nowPoint / y][nowPoint % y] + gr[nowPoint].path[i].second);
        if (max > board[k1][k2]){
          max = board[k1][k2];
        }
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
  vector<graph> gr(x * y);
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
        gr[i * y + j].path.push_back(make_pair(-1, 0));
      else{
        if (i > 0 && array[i - 1][j] != '#')
          gr[i * y + j].path.push_back(make_pair(i * y + j - y, 1));
        if (j > 0 && array[i][j - 1] != '#')
          gr[i * y + j].path.push_back(make_pair(i * y + j - 1, 1));
        if (j < y - 1 && array[i][j + 1] != '#')
          gr[i * y + j].path.push_back(make_pair(i * y + j + 1, 1));
        if (i < x - 1 && array[i + 1][j] != '#')
          gr[i * y + j].path.push_back(make_pair(i * y + j + y, 1));
      }
      cout << array[i][j];
    }
    cout << endl;
  }
  cout << "Graph:" << endl;
  for (int i = 0; i < x * y; i++){
    int l = gr[i].path.size();
    cout << i << " - ";
    if (l){
      for (int j = 0; j < l; j++){
        if (gr[i].path[j].first == -1){
          cout << "None";
          continue;
        }
        cout << gr[i].path[j].first << " ";
      }
    }
    else{
      cout << "None";
    }
    cout << endl;
  }
  cout << "BFS result is:" << endl;
  path[s_x][s_y] = 0;
  Breadth_first_search(s_x * y + s_y, f_x * y + f_y, gr, path, y);
  for (int i = 0; i < x; i++){
    for (int j = 0; j < y; j++){
      cout << path[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}