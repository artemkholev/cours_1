#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dop(int ml, vector<int> &answer, vector<int> &array_place);

int main(){
  int n = 0, mx = 0, ml = 0;
  cin >> n;
  vector<int> array(n);
  vector<int> array_new;
  vector<int> array_place(n);
  vector<int> answer;
  for (int i = 0; i < n; i++)
    cin >> array[i];
  for (int i = 0; i < n; i++){
    array_place[i] = -1.0e+2;
    array_new.push_back(1);
    for (int j = 0; j < i; j++){
      if ((array[i] >= array[j]) && ((array_new[j] + 1) >= array_new[i])){
        array_place[i] = j;
        array_new[i] = (array_new[j] + 1);
      }
    }
  }
  mx = array_new[0];
  for (int i = 0; i < n; i++){
    if (mx <= array_new[i]){
      mx = array_new[i];
      ml = i;
    }
  }
  dop(ml, answer, array_place);
  cout << "Best length = ";
  cout << mx << endl;
  cout << "Best combo is:  ";
  int size_array = (int)answer.size();
  for (int i = size_array - 1; i >= 0; i--)
    cout << array[answer[i]] << ' ';
}

void dop(int ml, vector<int> &answer, vector<int> &array_place){
  while (ml != -1.0e+2){
    answer.push_back(ml);
    ml = array_place[ml];
  }
}