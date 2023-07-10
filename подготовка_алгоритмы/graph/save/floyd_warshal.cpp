#include <iostream>
#include <vector>

using namespace std;

#define inf 10000000

struct Graph{
  vector<pair<int, int>> neighbors;
};

void floyd_warshal(vector<vector<int>> &distance, Graph *array, int n){
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
      }
    }
  }
}

int main(){
  int n = 0, start_pos = 0, end = 0;
  cin >> n >> start_pos >> end;
  struct Graph array[n];
  vector<vector<int>> distance(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++)
    distance[i][i] = 0;
  for (int i = 0; i < n; i++){
    int x, y, d;
    cin >> x >> y >> d;
    distance[x][y] = d;
    array[x].neighbors.push_back(make_pair(y, d));
  }

  floyd_warshal(distance, array, n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << distance[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}