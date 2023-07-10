#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define INF 1000
#define FLAG -1

using namespace std;

typedef struct Gtaph{
  int name;
  vector<pair<int, int>> path;
}graph;

int findNames(vector<string> names, string str){
  for (int i = 0; i < names.size(); i++){
    if ((str == names[i])){
      return i;
    }
  }
  return -1;
}

void prima(vector<graph> array, vector<int> &dist, vector<int> &vertFix, vector<int> &f, int &suma){
  priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> queue_g;
  dist[0] = 0;
  queue_g.push({0, 0});

  while (!queue_g.empty()){
    int nV = queue_g.top().second; // vertex
    queue_g.pop();
    if (f[nV] == 1)
      continue;
    f[nV] = 1;
    
    for (auto i : array[nV].path){
      int vertex = i.first;
      int len = i.second;

      if (f[vertex] == 0 && (dist[vertex] > len)){
        dist[vertex] = len; 
        queue_g.push({len, vertex});
        vertFix[vertex] = nV;
      }
    }
  }
}

int main(){ 
  vector<string> names;
  vector<graph> array;
 
  string a;
  cin >> a;
  while (a.compare(".")){
    int pos = findNames(names, a);
    if (pos == -1){
      array.push_back(graph());
      names.push_back(a);
      pos = names.size() - 1;
      array[pos].name = pos;
    }

    string pTo;
    int length;
    int pToNames;
    cin >> pTo >> length;
    pToNames = findNames(names, pTo);
    if (pToNames == -1){
      array.push_back(graph());
      names.push_back(pTo);
      pToNames = names.size() - 1;
      array[pToNames].name = pToNames;
    }
    array[pos].path.push_back({pToNames, length});
    cin >> a;
  }

  int suma = 0;
  int count = array.size();
  vector<int> dist(count, INF);
  vector<int> vertFix(count, FLAG);
  vector<int> f(count, 0);
  if (count != 0){
    prima(array, dist, vertFix, f, suma);
    for (int i = 1; i < count; i++)
      cout  << names[vertFix[i]] << " " << names[i] << " " << endl;
  }
  
  for (int i = 0; i < count; i++){
    suma += dist[i];
  }
  cout << suma << endl;
  return 0;
}

// 0 
// 1 
// 4
// 0 
// 7 
// 8
// 1 
// 2 
// 8
// 1 
// 7 
// 11
// 2 
// 3 
// 7
// 2 
// 8 
// 2
// 2 
// 5 
// 4
// 3 
// 4 
// 9
// 3 
// 5 
// 14
// 4 
// 5 
// 10
// 5 
// 6 
// 2
// 6 
// 7 
// 1
// 6 
// 8 
// 6
// 7 
// 8 
// 7
// .

/*
D
A
5
D
B
9
D
E
15
D
F
6
A
B
7
F
E
8
F
G
11
B
C
8
B
E
7
E
C
5
E
G
9
.
*/