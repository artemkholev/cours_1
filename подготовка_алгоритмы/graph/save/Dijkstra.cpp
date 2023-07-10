#include <iostream>
#include <vector>

using namespace std;

#define inf 10000000

struct Graph{
  vector<pair<int, int>> neighbors;
};

void dijkstra(vector<int> &distance, vector<int> &visited, Graph *array, int n){
  while (1){
    int pos = -1;
    for (int i = 0; i < n; i++){
      if (!visited[i] && distance[i] < inf){
        pos = i;
      }
    }
    if (pos == -1)
      break;
    visited[pos] = 1;
    for (int i = 0; i < size(array[pos].neighbors); i++){
      pair<int,int> k = array[pos].neighbors[i];
      distance[k.first] = min(distance[k.first], distance[pos] + k.second);
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
  dijkstra(distance, visited, array, n);
  cout << distance[end] << endl;
  return 0;
}