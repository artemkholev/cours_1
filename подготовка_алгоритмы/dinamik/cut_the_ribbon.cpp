#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n = 0, a = 0, b = 0, c = 0;
  cin >> n >> a >> b >> c;
  vector<int> dop(n + 1);
  for (int i = 0; i <= n; i++)
    dop[i] = -1;
  dop[0] = 0;
  for (int i = 1; i <= n; i++){
    int answer = -1;
    if (i - a >= 0 && dop[i - a] != -1){
      answer = max(dop[i - a] + 1, answer);
    }
    if (i - b >= 0 && dop[i - b] != -1){
      answer = max(dop[i - b] + 1, answer);
    }
    if (i - c >= 0 && dop[i - c] != -1){
      answer = max(dop[i - c] + 1, answer);
    }
    dop[i] = answer;
  }
  for (int i = 0; i <= n; i++)
    cout << dop[i] << " ";
  cout << endl;
  cout << dop[n] << endl;
  return 0;
}