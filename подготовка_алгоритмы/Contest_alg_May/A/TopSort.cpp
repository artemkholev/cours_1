#include <iostream>
#include <vector>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Structure {
public:
    int number;
    list<int> topSortList;
    vector<vector<int>> vertexes_to;
    vector<bool> visited_vertexes;

    Structure(int count_for_save){
        number = count_for_save;
        visited_vertexes.resize(number);
        vertexes_to.resize(number);
    }

    void DFS(int pos_v){
        visited_vertexes[pos_v] = true;
        for (auto vert : vertexes_to[pos_v]){
            if (visited_vertexes[vert] == false){
                visited_vertexes[vert] = true;
                DFS(vert);
            }
        }
        topSortList.push_back(pos_v);
    }

    void get_elem(int from, int to){
        vertexes_to[from].push_back(to);
    }
};

int main(){
    int count_for_save = 0, from = 0, to = 0;

    cin >> count_for_save;
    Structure topSortGraph(count_for_save);
     for (int  i = 0; i < count_for_save; i++){
       cin >> from >> to;
       topSortGraph.get_elem(from, to);
     }
//    while (cin >> from >> to)
//        graph.add(from, to);

    for (int i = 0; i < count_for_save; i++){
        std::sort(topSortGraph.vertexes_to[i].begin(), topSortGraph.vertexes_to[i].end());
    }
    for (int  i = 0; i < count_for_save; i++){
        if (topSortGraph.visited_vertexes[i] == false){
            topSortGraph.DFS(i);
        }
    }
    for (auto i: topSortGraph.topSortList){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
