#include <iostream>
#include <map>
#include <vector>
using namespace std;

class DS {
public:
    int max_size = 0;
    vector<int> size;
    vector<pair<int, vector<int>>> saveData;
    map<int, int> pElem;

    void unionSets(int distination, int sourse) {
        int posSourse = findSet(sourse - 1),
            posDistination = findSet(distination - 1);
        if (posSourse != posDistination) {
            int sum = size[posSourse] + size[posDistination];
            if (max_size < sum)
                max_size = sum;
            size[posDistination] = sum;
            size[posSourse] = 0;
            pElem[posSourse] = posDistination;
//            saveData[posDistination].second.insert(saveData[posDistination].second.end(), saveData[posSourse].second.begin(), saveData[posSourse].second.end());
//            saveData[posSourse].second.clear();
        }
        cout << max_size << endl;
    }

    int findSet(int findElem) {
        if (findElem == pElem[findElem])
            return findElem;
        else
            return pElem[findElem] = findSet(pElem[findElem]);
    }

    void makeSet(vector<pair<int, vector<int>>> &inputData) {
        for (auto i: inputData)
            pElem[i.first] = i.first;
    }
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    DS DJset;
    for (int i = 0; i < n; ++i) DJset.saveData.push_back({i + 1, {}});
    DJset.makeSet(DJset.saveData);
    for (int i = 0; i < n; i++) {
        int sizeElem = 0;
        cin >> sizeElem;
//        DJset.saveData[i].second.resize(sizeElem);
//        fill(DJset.saveData[i].second.begin(),  DJset.saveData[i].second.end(), 1);
        if (sizeElem > DJset.max_size)
            DJset.max_size = sizeElem;
        DJset.size.push_back(sizeElem);
    }
    for (int i = 0; i < m; i++) {
        int distination = 0, sourse = 0;
        cin >> distination >> sourse;
        DJset.unionSets(distination, sourse);
    }
    return 0;
}