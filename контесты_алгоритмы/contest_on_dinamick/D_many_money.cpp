#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
  int n = 0, m = 0;
  char p[10];
  cin >> n >> m;
  int c = 0, r = 0;
  vector<vector<int>> array(n, vector<int>(m, 0));
  vector<vector<int>> dop(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> p;
      if (p[0] == 'S'){
        array[i][j] = 0;
        c = i, r = j;
      }
      else
        array[i][j] = stoi(p);
    }
  }

  for (int i = c + 1; i < n; i++)
    dop[i][r] = array[i][r] + dop[i - 1][r];
  for (int i = r + 1; i < m; i++)
    dop[c][i] = array[c][i] + dop[c][i - 1];

   int i;
   c < m - 1 ? (i = c + 1) : (i = n - 1);
  for (int i = c + 1; i < n; i++){
    int j;
    r < m - 1 ? (j = r + 1) : (j = m - 1);
    for (; j < m; j++){
      dop[i][j] = max(dop[i - 1][j], dop[i][j - 1]) + array[i][j];
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << dop[i][j] << " ";
    }
    cout << endl;
  }

  int cost = dop[n-1][m-1];
  vector<pair<int, int>> pair;
  pair.emplace_back(n - 1, m - 1);
  n--;
  m--;

  while (n - 1 >= c || m - 1 >= r){
    if (n - 1 >= c && (dop[n - 1][m] >= dop[n][m - 1])){
      n--;
      pair.emplace_back(n, m);
    }
    else if (m - 1 >= r){
      m--;
      pair.emplace_back(n, m);
    }
  }
  cout << "Path:\n" << "(" << c << "," << r <<") ";
  for (int i = pair.size() - 2; i >= 0; i--)
    cout << "(" << pair[i].first << "," << pair[i].second <<") ";

  cout << "\n" << "Coins: " << cost << endl;
  return 0;
}