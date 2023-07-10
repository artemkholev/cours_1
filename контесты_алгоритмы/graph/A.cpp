#include <iostream>
#include <vector>
using namespace std;

void graph(vector<vector<int>> &array, int n){
  int offset_x[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
  int offset_y[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
  for (int i = 0; i < n * n; i++){
    cout << i << " - ";
    for (int j = 0; j < 8; j++){
      int one = offset_x[j] + (i % n);
      int two = offset_y[j] + (i / n);
      if (one >= 0 && two >= 0 && one < n && two < n){
        array[i].push_back(two * n + one);
        cout << two * n + one << " ";
      }
    }
    cout << endl;
  }
}

int f(int x, int y, vector<vector<int>> &array, vector<vector<int>> &board, int n, int t){
  if (n * n <= t)
    return 1;
  for (int i = 0; i < size(array[x * n + y]); i++){
    int k1 = array[x * n + y][i] % n;
    int k2 = array[x * n + y][i] / n;
    if (board[k2][k1] == 0){
      board[k2][k1] = t;
      if (f(k2, k1, array, board, n, t + 1))
        return 1;
      board[k2][k1] = 0;
    }
  }
  return 0;
}

int main(){
  int n = 0, x = 0, y = 0;
  cin >> n >> x >> y;
  vector<vector<int>> array(n * n);
  vector<vector<int>> board(n, vector<int>(n));
  
  cout << "Graph:" << endl;
  graph(array, n);
  cout << "Hamiltonian path:" << endl;
  board[x][y] = 1;
  if ( f(x, y, array, board, n, 1) ){
    board[x][y] = 0;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }
  else 
    cout << "No way" << endl;
  return 0;
}