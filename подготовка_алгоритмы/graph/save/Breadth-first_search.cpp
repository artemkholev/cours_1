#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
class GRAPH{
  int number;
  vector<list<int>> list_neighbors;
  public:
      GRAPH(int number);
      void to_lists_point(int first, int second);
      void Breadth_first_search(int start_pos);
};

GRAPH::GRAPH(int count){
  number = count;
  // list_neighbors = new list[count];
  list_neighbors.resize(count);
}
void GRAPH::to_lists_point(int first, int second){
    list_neighbors[first].push_back(second);
}
 
void GRAPH::Breadth_first_search(int start_pos){
  int now_point = 0;
  list<int> point_queue;
  vector<int> last_point(number);
  last_point[start_pos] = 1;
  point_queue.push_back(start_pos);
  while (point_queue.empty() == 0){
    now_point = point_queue.front();
    cout << now_point << " ";
    point_queue.pop_front();
    for (const auto i : list_neighbors[now_point]){
      if (last_point[i] == 0) {
        point_queue.push_back(i);
        last_point[i] = 1;
      }
  }
  }
}
int main(){
    GRAPH graph(4);
    graph.to_lists_point(0, 1);
    graph.to_lists_point(0, 2);
    graph.to_lists_point(1, 2);
    graph.to_lists_point(2, 0);
    graph.to_lists_point(2, 3);
    graph.to_lists_point(3, 3);
    cout << endl;
    graph.Breadth_first_search(2);
    cout << endl;
    return 0;
}