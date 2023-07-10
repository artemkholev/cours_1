#include <iostream>
#include <map>
#include <vector>
using namespace std;

class DS {
    public:
        map<int, int> pElem;
        int findSet(int findElem) {
            if (findElem == pElem[findElem]) return findElem;
            return findSet(pElem[findElem]);
        }

        void makeSet(vector<int> &inputData) {
            for (int i: inputData) pElem[i] = i;
        }

        void unionSets(int x, int y) {
            pElem[findSet(x)] = findSet(y);
        }
};

void printSets(vector<int> &inputData, DS &DJset) {
    for (int i: inputData)
        cout << DJset.findSet(i) << " ";
    cout << endl;
}

int main() {
    int n;
    vector<int> saveData;
    cin >> n;
    for (int i = 0; i < n; ++i) saveData.push_back(i + 1);

    DS DJset;

    DJset.makeSet(saveData);
    printSets(saveData, DJset);

    DJset.unionSets(4, 3);        // 4 and 3 are in the same set
    printSets(saveData, DJset);

    DJset.unionSets(2, 1);        // 1 and 2 are in the same set
    printSets(saveData, DJset);

    DJset.unionSets(1, 3);        // 1, 2, 3, 4 are in the same set
    printSets(saveData, DJset);
    return 0;
}