#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n = 0, k = 0, s = 0;
  cin >> n >> k >> s;
  vector<int> array(s);
  vector<int> dop(n);
  for (int i = 0; i < s; i++){
    cin >> array[i];
  }
  for (int i = 0; i < n; i++){
    dop[i] = -1;
  }
  dop[0] = 0;
  int p = 0;
  for (int i = 1; i < n; i++){
    if (i < (k * (dop[i - 1] + 1)))
      dop[i] = dop[i - 1];
    while (array[p] < (k * (dop[i - 1] + 1)) && p != s - 1){
      p++;
    }
    if (i == array[p] - 1 && dop[i - 1] != -1 && (k * (dop[i - 1] + 1) < n)){
      dop[i]++;
      p++;
    }
  }
  for (int i = 0; i < n; i++){
    cout << dop[i] << " ";
  }
  cout << endl;

  cout << dop[n - 1] << endl;
  return 0;
}