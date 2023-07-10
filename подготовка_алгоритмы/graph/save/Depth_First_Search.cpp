//program with segments

// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> visited(100);
// int n;
// void dfs(int v, vector<vector<int>> array){
//   for (int i = 0; i < n; i++){
//     if (array[v][i] && !visited[i]){
//       cout << i << " ";
//       visited[i] = 1;
//       dfs(i, array);
//     }
//   }
// }
// int main(){
//   cin >> n;
//   vector<vector<int>> array(n , vector<int>(n, 0));
//   for (int i = 0; i < n; i++){
//     for (int j = 0; j < n; j++)
//       cin >> array[i][j];
//   }
//   cout << endl;
//   for (int i = 0; i < n; i++){
//     if (!visited[i]){
//       cout << i << " ";
//       visited[i] = 1;
//       dfs(i, array);
//       cout << endl;
//     }
//   }
//   return 0;
// }
// /*
// 7
// 0 1 0 0 0 0 1
// 1 0 0 0 0 1 0
// 0 0 0 1 0 0 0 
// 0 0 1 0 0 0 0
// 0 0 0 0 0 0 0
// 0 1 0 0 0 0 1
// 1 0 0 0 0 1 0
// */

//program with massiv of graph

// #include <iostream>
// #include <vector>
// using namespace std;
// vector<int> visited(100);
// int n;
// void dfs(int v, vector<vector<int>> array){
//   for (int i = 0; i < size(array[v]); i++){
//     if (!visited[array[v][i]]){
//       cout << array[v][i] << " ";
//       visited[array[v][i]] = 1;
//       dfs(array[v][i], array);
//     }
//   }
// }
// int main(){
//   cin >> n;
//   vector<vector<int>> array(n);
//   for (int i = 0; i < 10; i++){
//     int x,y;
//     cin >> x >> y;
//     array[x].push_back(y);
//   }
//   cout << endl;
//   for (int i = 0; i < n; i++){
//     if (!visited[i]){
//       cout << i << " ";
//       visited[i] = 1;
//       dfs(i, array);
//       cout << endl;
//     }
//   }
//   return 0;
// }
// /*
// 7
// 0 1
// 0 6
// 1 0
// 1 5
// 2 3
// 3 2
// 5 1
// 5 6
// 6 0
// 6 5
// */

//program with adjacency lists 

// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>
// using namespace std;
// class Graph{
//   int number;
//   vector<list<int>> array;
//   public:
//     Graph(int count);
//     vector<int> visited;
//     void dfs(int v);
//     void add(int x, int y);
// };
// Graph::Graph(int count){
//   array.resize(count);
//   visited.resize(count);
//   number = count;
// }
// void Graph::add(int x, int y){
//   array[x].push_back(y);
// }
// void Graph::dfs(int v){
//   visited[v] = 1;
//   cout << v << " ";
//   for (auto i : array[v]){
//     if (!visited[i]){
//       visited[i] = 1;
//       dfs(i);
//     }
//   }
// }
// int main(){
//   int n = 0, x = 0, y = 0;
//   cin >> n;
//   Graph graph(n);
//   for (int  i = 0; i < 10; i++){
//     cin >> x >> y;
//     graph.add(x, y);
//   }
//   // while (cin >> x >> y){
//   //   graph.add(x, y);
//   // }
//   for (int  i = 0; i < n; i++){
//     if (!graph.visited[i]){
//       graph.dfs(i);
//       cout << endl;
//     }
//   }
//   return 0;
// }
// // 7
// // 0 1
// // 0 6
// // 1 0
// // 1 5
// // 2 3
// // 3 2
// // 5 1
// // 5 6
// // 6 0
// // 6 5

//program with count of segment

// #include <iostream>
// #include <vector>
// using namespace std;
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
// // 7
// // 0 1
// // 0 6
// // 1 0
// // 1 5
// // 2 3
// // 3 2
// // 5 1
// // 5 6
// // 6 0
// // 6 5


//program with find vertuax yes or not 

// #include <iostream>
// #include <vector>
// #include <bits/stdc++.h>
// using namespace std;
// class Graph{
//   int number;
//   vector<list<int>> array;
//   public:
//     Graph(int count);
//     vector<int> visited;
//     int dfs(int v, int f);
//     void add(int x, int y);
// };
// Graph::Graph(int count){
//   array.resize(count);
//   visited.resize(count);
//   number = count;
// }
// void Graph::add(int x, int y){
//   array[x].push_back(y);
// }
// int Graph::dfs(int v, int f){
//   visited[v] = 1;
//   if (v == f){
//     return 1;
//   }
//   for (auto i : array[v]){
//     if (!visited[i]){
//       visited[i] = 1;
//       if (dfs(i, f)){
//         return 1;
//       }
//     }
//   }
//   return 0;
// }
// int main(){
//   int f = 0, answer = 0;
//   int n = 0, x = 0, y = 0;
//   cin >> n;
//   Graph graph(n);
//   for (int  i = 0; i < 10; i++){
//     cin >> x >> y;
//     graph.add(x, y);
//   }
//   cin >> f;
//   for (int  i = 0; i < n; i++){
//     if (!graph.visited[i]){
//       if (graph.dfs(i, f)){
//         answer = 1;
//         break;
//       }
//     }
//   }
//   if (!answer)
//     cout << "No" << endl;
//   else 
//     cout << "Yes" << endl;
//   return 0;
// }
// // 7
// // 0 1
// // 0 6
// // 1 0
// // 1 5
// // 2 3
// // 3 2
// // 5 1
// // 5 6
// // 6 0
// // 6 5