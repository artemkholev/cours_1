#include <iostream>
#include <vector>

using namespace std;

#define inf 10000000

struct Graph{
  vector<pair<int, int>> neighbors;
};

void ford_bellman(vector<int> &distance, vector<int> &visited, Graph *array, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (distance[j] < inf){
        for (int v = 0; v < size(array[j].neighbors); v++){
          pair<int,int> k = array[j].neighbors[v];
          distance[k.first] = min(distance[k.first], distance[j] + k.second);
        }
      }
    }
  }
}

int main(){
  int n = 0, start_pos = 0, end = 0;
  cin >> n >> start_pos >> end;;
  struct Graph array[n];
  vector<int> distance(n, inf);
  vector<int> visited(n, 0);
  for (int i = 0; i < n; i++){
    int x, y, d;
    cin >> x >> y >> d;
    array[x].neighbors.push_back(make_pair(y, d));
  }
  distance[start_pos] = 0;
  ford_bellman(distance, visited, array, n);
  cout << distance[end] << endl;

  for (int i = 0; i < n; i++){
    cout << distance[i] << " ";
  }
  return 0;
}