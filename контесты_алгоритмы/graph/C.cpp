#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>
#include <cmath>
using namespace std;

struct Graph{
  double x = 0, y = 0;
  vector<int> names_to;
  double dist = 10000;
};

int find(string word, vector<string> str){
  for (int i = 0; i < str.size(); i++){
    if (str[i] == word)
      return i;
  }
  return -1;
}

int r(int n, vector<int> str){
  for (int i = 0; i < str.size(); i++){
    if (str[i] == n)
      return i;
  }
  return -1;
}

void find_path(vector<int> &path, Graph *array, vector<vector<int>> &graph, int start, int f, int n){
  double min = 0;
  int min_pos = start;
  vector<int> save;
  vector<int> dop(n, -1);
  for (int i = 0; i < n - 1; i++){
    save.push_back(min_pos);
    for (int k = 0; k < array[min_pos].names_to.size(); k++){
      int j = array[min_pos].names_to[k];
      double dist =  sqrt((array[min_pos].x - array[j].x)*(array[min_pos].x - array[j].x) + (array[min_pos].y - array[j].y)*(array[min_pos].y - array[j].y));
      if ((dist + array[min_pos].dist) < array[j].dist && r(j, save) == -1){
        array[j].dist = dist + array[min_pos].dist;
        path[j] = min_pos;
        dop[j] = j;
      }
    }
    min = 100000;
    for (int k = 0; k < n; k++){
      if (array[k].dist < min && dop[k] != -1){
        min = array[k].dist;
        min_pos = k;
      }
    }
    dop[min_pos] = -1;
  }
}

int main(){ 
  int n = 0, str_start = 0, str_end = 0;
  cin >> n;
  struct Graph array[n];
  vector<vector<int>> graph(n, vector<int>(n, 10000));
  vector<string> str;
  string path;
  getline(cin, path);
 
  for (int i = 0; i < n; i++){
    getline(cin, path);
    stringstream ist(path);
    string word;
    ist >> word;
    int pos = 0, p = 0;
    pos = find(word, str);
    if (pos == -1){
      str.push_back(word);
      pos = str.size() - 1;
    }
    ist >> word;
    array[pos].x = stoi(word);
    ist >> word;
    array[pos].y = stoi(word);
    for (; ist >> word;){
      p = find(word, str); 
      if ( p == -1){
        str.push_back(word);
        p = str.size() - 1;
        array[pos].names_to.push_back(p);
      }
      else{
        array[pos].names_to.push_back(p);
      }
    }
  } 
  cin >> path;
  str_start = find(path, str);
  cin >> path;
  str_end = find(path, str);
  vector<int> pos_v(n);
  array[str_start].dist = 0;
  find_path(pos_v, array, graph, str_start, str_end, n);
  if (array[str_end].dist == 10000){
    cout << "Path:" << endl;
    cout << "No way";
    exit(EXIT_SUCCESS);
  }
  else
    cout << "Path is not greater than " << ceil(array[str_end].dist) << endl;
  cout << "Path:" << endl;
  vector<int> p;
  int k = str_end;
  p.push_back(k);
  while (k != str_start){
    k = pos_v[k];
    p.push_back(k);
  }
  for (int i = p.size() - 1; i >= 0; i--){
    cout << str[p[i]] << " ";
  }
  return 0;
}


















// 10000   109    64 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000    40 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// 10000 10000 10000 10000 10000 10000 10000 10000 10000 10000 
// Homburg Sirohi
/*
10
Sirohi 8 14 Budingen 
Concord 61 69 Homburg Shaoyang 
Budingen 58 4 Sirohi Homburg 
Pokaran 98 61 
Pushkar 4 54 
Salto 8 47 
Homburg 4 99 Concord Budingen 
Sojat 38 15 
Shaoyang 99 82 Concord 
Chinhoyi 70 47 
Homburg Sirohi

161

4 
NN 0 0 KSTOVO 
KSTOVO 1 1 NN AVTOZ 
AVTOZ 2 2 KSTOVO 
RODIONOVA 999 999 
NN RODIONOVA

4 
NN 0 0 KSTOVO 
KSTOVO 1 1 AVTOZ NN 
AVTOZ 2 2 KSTOVO 
RODIONOVA 999 999 
RODIONOVA AVTOZ

10 
Homburg 9 89 Bayswater Sirohi 
Shaoyang 89 86 Turen Bayswater 
Plainfield 0 96 Sirohi 
Sirohi 97 52 Homburg Pali Plainfield Rivera 
Bayswater 41 70 Homburg Budingen Pali Shaoyang 
Rivera 83 54 Pali Sirohi 
Turen 43 60 Salto Shaoyang 
Pali 7 16 Sirohi Bayswater Rivera 
Salto 2 66 Turen 
Budingen 88 57 Bayswater 
Turen Plainfield
*/