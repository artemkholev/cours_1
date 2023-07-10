#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> & arr, int j, int n){
    for (int i = 0; i < n; i++){
        if (arr[i] == j)
            return 0;
    }
    return 1;
}

int main(){
    int n = 0, sum_min = 1000000;
    vector<int> arr(n);
    vector<int> arr_min(n);
    cin >> n;
    vector<vector<int>> array(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> array[i][j];
        }
    }

    int min_l = 0, flag = 0, kk = 0;
    for (int i = 0; i < n; i++){
        int pos_min = i, mark = 0, sum = 0;
        arr.push_back(i);
        for (int k = 0; k < n - 1; k++){
            min_l = 100000;
            mark = 0;
            for (int j = 0; j < n; j++){
                if (array[pos_min][j] == 0 || pos_min == j)
                    continue;
                else if (find(arr, j, arr.size()) && min_l > array[pos_min][j]){   
                    min_l = array[pos_min][j];
                    kk = j;
                    mark = 1;
                }
            }
            if (mark == 0){
                arr.clear();
                break;
            }
            sum += min_l;
            pos_min = kk;
            arr.push_back(pos_min); 
        }
        if (mark == 0 || (array[pos_min][i] == 0 && mark == 1)){
            mark = 0;
            arr.clear();
            continue;
        }
        sum += array[pos_min][i];
        if (sum_min > sum){
            flag = 1;
            sum_min = sum; 
            arr_min.clear();
            arr_min = arr;
            arr_min.push_back(i);
            arr.clear();
        }
        arr.clear();
    }
    if (flag == 0){
        cout << "Lost";
        exit(EXIT_SUCCESS);
    }
    cout << "Path:\n";
    for (int i = 0; i < n + 1; i++)
        cout << arr_min[i] << " ";
    cout << "\nCost: " << sum_min;
    return 0;
}