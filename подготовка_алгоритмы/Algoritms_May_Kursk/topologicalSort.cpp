#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <list>
using namespace std;

class Graph{
  public:
    list<int> vect;
    int number;
    vector<list<int>> gr;
    vector<int> visited;
    //function 
    Graph(int count);
    void dfs(int v);
    void add(int x, int y);
};

Graph::Graph(int count){
  gr.resize(count);
  visited.resize(count);
  number = count;
}

void Graph::add(int x, int y){
  gr[x].push_back(y);
}

void Graph::dfs(int v){
  visited[v] = 1;
  // cout << v << " ";
  for (auto i : gr[v]){
    if (!visited[i]){
      visited[i] = 1;
      dfs(i);
    }
  }
  vect.push_back(v);
}

int main(){
  int n = 0, 
      x = 0, 
      y = 0;

  cin >> n;
  Graph graph(n);
  // for (int  i = 0; i < 10; i++){
  //   cin >> x >> y;
  //   graph.add(x, y);
  // }
  while (cin >> x >> y){
    graph.add(x, y);
  }

  for (int i = 0; i < n; i++){
    graph.gr[i].sort();
  }
  for (int  i = 0; i < n; i++){
    if (!graph.visited[i]){
      graph.dfs(i);
      cout << endl;
    }
  }
  for (auto i: graph.vect){
    cout << i << " ";
  }
  cout << endl;
  return 0;
}













// vector<int> visited(100);
// int n, count;
// void dfs(int v, vector<vector<int>> array){
//   for (int i = 0; i < size(array[v]); i++){
//     if (!visited[array[v][i]]){
//       cout << array[v][i] << " ";
//       visited[array[v][i]] = count;
//       dfs(array[v][i], array);
//     }
//   }
// }
// int main(){
//   cin >> n;
//   count = 0;
//   int k = 1;
//   vector<vector<int>> array(n);
//   for (int i = 0; i < 10; i++){
//     int x,y;
//     cin >> x >> y;
//     array[x].push_back(y);
//   }
//   cout << endl;
//   for (int i = 0; i < n; i++){
//     if (!visited[i]){
//       cout << "\nsegment: " << ++count << "-> ";
//       cout << i << " ";
//       visited[i] = count;
//       dfs(i, array);
//       cout << endl;
//     }
//   }
//   cout << "Count segments: " << count << endl;
//   return 0;
// }

// 0
// 1 2 3