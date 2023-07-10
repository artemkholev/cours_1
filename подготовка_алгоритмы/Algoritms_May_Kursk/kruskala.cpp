#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 1000
#define FLAG -1

using namespace std;

typedef struct Gtaph{
  vector<pair<int, pair<int, int>>> objectGraph;
}graph;

int findNames(vector<string> names, string str){
  for (int i = 0; i < names.size(); i++){
    if ((str == names[i])){
      return i;
    }
  }
  return -1;
}

int find(int v, vector<int> set){
  if (set[v] == v){
    return v;
  }
  return set[v] = find(set[v], set);
}

int merge(int a, int b, vector<int> &set, vector<int> &countV){
  int one = find(a, set);
  int two = find(b, set);
  if (one != two){
    if(countV[one] > countV[two]){
      int k = one;
      one = two;
      two = k;
    } 
    set[one] = two;
    if (countV[one] == countV[two]){
      countV[two]++;
    }
    return 1;
  } 
  return 0;
}

void kurskal(graph g, vector<int> &set, vector<int> &countV, int &suma, vector<pair<int, int>> &answer){
  for (auto i : g.objectGraph){
    int len = i.first;
    int a = i.second.first;
    int b = i.second.second;
    int one = find(a, set);
    int two = find(b, set);
    if (one != two){
      suma += len;
      answer.push_back({a, b});
      merge(a, b, set, countV);
    }
  }
}

int main(){ 
  graph g;
  string p, pTo;
  vector<string> names;
  vector<pair<int, int>> answer;
  int n = 0;
  int length = 0;
  cin >> p;
  while (p.compare(".")){
    int posOne = findNames(names, p);
    if (posOne == -1){
      names.push_back(p);
      posOne = names.size() - 1;
    }
    cin >> pTo >> length;
    int posTwo = findNames(names, pTo);
    if (posTwo == -1){
      names.push_back(pTo);
      posTwo = names.size() - 1;
    }
    g.objectGraph.push_back({length, {posOne, posTwo}});
    cin >> p;
  }

  int suma = 0;
  n = names.size();
  vector<int> set(n);
  vector<int> countV(n);
  for (int i = 0; i < names.size(); i++){
    set[i] = i;
    countV[i] = 1;
  }
  sort(g.objectGraph.begin(), g.objectGraph.end());
  kurskal(g, set, countV, suma, answer);

  cout << "\n" << suma << endl;
  for (int i = 0; i < answer.size(); i++){
    cout << names[answer[i].first] << " " <<  names[answer[i].second]  << endl;
  }
  set.clear();
  countV.clear();
  g.objectGraph.clear();
  return 0;
}

/*
A
D
5
A
B
7
B
D
9
B
C
8
B
E
7
C
E
5
D
F
6
D
E
15
F
E
8
F
G
11
E
G
9
.
*/