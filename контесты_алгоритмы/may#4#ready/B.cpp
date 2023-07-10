#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void enter_array(int &n, vector<int> &array) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        array.push_back(elem);
    }
}

bool comp(int element1, int element2){
    return (element1 < element2);
}

int main() {
    int n1, n2, n3;
    vector<int> answers(3);
    vector<int> array_first,
                array_second,
                array_third;
    enter_array(n1, array_first);
    enter_array(n2, array_second);
    enter_array(n3, array_third);

    int min_value, max_value, result = 100000000;
    int index1 = 0, index2 = 0, index3 = 0;

    while (index1 < n1 || index2 < n2 || index3 < n3) {
        min_value = min({array_first[index1], array_second[index2], array_third[index3]}, comp);
        max_value = max({array_first[index1], array_second[index2], array_third[index3]}, comp);
        if (max_value - min_value < result) {
            result = max_value - min_value;
            answers[0] = array_first[index1];
            answers[1] = array_second[index2];
            answers[2] = array_third[index3];
        }
        if (min_value == array_first[index1] && index1 < n1) index1++;
        else if (min_value == array_second[index2] && index2 < n2) index2++;
        else if (min_value == array_third[index3] && index3 < n3) index3++;
        else break;
    }
    cout << "Numbers = ";
    for (int i = 0; i < 3; i++) {
        cout << answers[i] << " ";
    }
    cout << "\nResult = " << result;
    return 0;
}