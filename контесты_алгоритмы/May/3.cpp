#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Structure {
public:
    int number;
    vector<vector<int>> topSortList;
    vector<vector<int>> vertexes_to;
    vector<int> visited_vertexes;

    Structure(int count_for_save){
        number = count_for_save;
        visited_vertexes.resize(number);
        vertexes_to.resize(number);
    }

    void general(int index, vector<int> elemOf, vector<int> array, vector<int> noIncoming) {
        if (noIncoming.size() == 0) {
            check_cycle(elemOf);
            topSortList.push_back(array);
        } else {
            int getNI = noIncoming[index];
            noIncoming.erase(noIncoming.begin() + index);
            array.push_back(getNI);

            for (int elemV: vertexes_to[getNI]) {
                elemOf[elemV]--;
                if (elemOf[elemV] == 0)
                    noIncoming.push_back(elemV);
            }
            if (noIncoming.size() == 0) {
                general(0, elemOf, array, noIncoming);
            } else {
                for (int i = 0; i < noIncoming.size(); i++)
                    general(i, elemOf, array, noIncoming);
            }
        }
    }

    void get_elem(int from, int to){
        vertexes_to[from].push_back(to);
    }

    void check_cycle(vector<int> elemOf) {
        for (int i = 0; i < elemOf.size(); i++) {
            if (elemOf[i]) {
                cout << "Impossible";
                exit(EXIT_SUCCESS);
            }
        }
    }
};

int main(){
    int count_for_save = 0;
    cin >> count_for_save;

    vector<int> elemOf(count_for_save, 0);

    Structure topSortGraph(count_for_save);
    for (int  i = 0; i < count_for_save; i++){
        int count_near = 0, elem = 0;
        cin >> count_near;
        for (int j = 0; j < count_near; j++) {
            cin >> elem;
            elemOf[elem]++;
            topSortGraph.get_elem(i, elem);
        }
    }

    vector<int> noIncoming;
    for (int i = 0; i < count_for_save; i++)
        if (elemOf[i] == 0)
            noIncoming.push_back(i);

    vector<int> array;

    if (noIncoming.size() == 0) {
        topSortGraph.check_cycle(elemOf);
    } else {
        for (int i = 0; i < noIncoming.size(); i++)
            topSortGraph.general(i, elemOf, array, noIncoming);
    }

    sort(topSortGraph.topSortList.begin(), topSortGraph.topSortList.end());
    int count = topSortGraph.topSortList.size();
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < topSortGraph.topSortList[i].size(); j++) {
            cout << topSortGraph.topSortList[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}