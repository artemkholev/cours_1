#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> do_array(int n){
  vector<int> array(n);
  for (int i = 0; i < n; i++)
  {
    array[i] = rand() % 10;
  }
  return array;
}

void print_array(vector<int>& array, int n){
  for (int i = 0; i < n; i++)
  {
    cout << array[i] << ' ';
  }
  cout << '\n';
}

int sort_array(vector<int>& array, int left, int right){
  int x = array[left + (rand() % (right - left))];
  if (x != right){
    swap(array[x], array[right]);
  }
  x = array[right];

  int p = left;
  for (int i = left; i < right; i++){
    if (array[i] <= x){
      swap(array[i], array[p]);
      p++;
    }
  }
  swap(array[right], array[p]);
  return p;
}

int find(vector<int>& array, int left, int right, int k){
  if (left - right == 0)
    return array[k];
  int p = sort_array(array, left, right);
  if (k < p)
    find(array, left, p - 1, k);
  else
    find(array, p, right, k);
}

int main(){
  srand(time(NULL));
  int n = 0, k = 0;
  setlocale(LC_ALL, "Rus");
  cout << "enter len array: ";
  cin >> n;
  cout << "enter K - pos number: ";
  cin >> k;
  if (k > n || k < 0){
    cout << "not correct -  K";
    exit(EXIT_SUCCESS);
  }
  vector<int> array = do_array(n);
  print_array(array, n);
  int p = find(array, 0, n - 1, k - 1);
  cout<< p << "\n";
  return 0;
}