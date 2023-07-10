#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    int sum = 0, max_sum = 0,
        ansver_start = 0, ansver_end = 0,
        min_lenght = 100000000;
    cin >> n >> k;
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && sum < k) {
            sum += array[j];
            j++;
        }
        if (sum < k) {
            break;
        } else if (min_lenght > j - i) {
            min_lenght = j - i;
            ansver_end = j - 1 ;
            ansver_start = i;
            max_sum = sum;
        } else if (min_lenght == j - i && sum > max_sum) {
            min_lenght = j - i;
            ansver_end = j - 1 ;
            ansver_start = i;
            max_sum = sum;
        }
        sum -= array[i];
    }
    if (max_sum < k) {
        cout << "No summ";
        exit(EXIT_SUCCESS);
    }
    cout << "Length = " << min_lenght << endl;
    cout << "Sum = " << max_sum << endl;
    cout << "Start = " <<  ansver_start << endl;
    cout << "Finish = " << ansver_end << endl;
    return 0;
}