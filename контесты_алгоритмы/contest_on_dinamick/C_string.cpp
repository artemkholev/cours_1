#include <iostream>
#include <vector>

using namespace std;

int d(char x, char y){
  if (x == y)
    return 0;
  else
    return 1;
}

int main(){
  string str, m;
  int n = 0, operation = 1000000, pos = 0;
  cin >> str >> n;
  vector<pair<int, int>> lin(n);
  int l1 = str.size();
  vector<string> stroks;
  for (int i = 0; i < n; i++){
    cin >> m;
    stroks.push_back(m);
  }

  for (int p = 0; p < n; p++){
    int l2 = stroks[p].size();
    vector<vector<int>> array(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 1; i < l1 + 1; i++)
      array[i][0] = array[i - 1][0] + 1;
    for (int i = 1; i < l2 + 1; i++)
      array[0][i] = array[0][i - 1] + 1;
    
    for (int i = 1; i < l1 + 1; i++){
      for (int j = 1; j < l2 + 1; j++){
        array[i][j] = min(array[i - 1][j] + 1, min(array[i][j - 1] + 1, array[i - 1][j - 1] + d(str[i - 1], stroks[p][j - 1])));
      }
    }
    
    if (operation >= array[l1][l2]){
      operation = array[l1][l2];
      while (pos != 0 && lin[pos - 1].second != array[l1][l2])
        pos--;
      lin[pos].first = p;
      lin[pos].second = array[l1][l2];
      pos++;
  }
    array.clear();
  }

  cout << "Most similar words = " << pos << endl;
  cout << "Minimal operations needed = " << operation << endl;
  for (int i = 0; i < pos - 1; i++)
    cout << stroks[lin[i].first] << endl;
  int a = stroks[lin[pos - 1].first].size();
  for (int i = 0; i < a; i++){
    cout << stroks[lin[pos - 1].first][i];
  }
  return 0;
}