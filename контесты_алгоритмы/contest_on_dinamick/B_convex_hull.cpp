#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
struct point{
    int x, y;
};
vector<point> shell;

int sort2(const void *one, const void *two);
int pos_two_point(point point_1, point point_2, point point_3);
int dist(point point_1, point point_2, point point_3);
void build(vector<point> &xy, int pos, int min_left, int max_right, int n, int* count_p);
void convex_hull(vector<point> xy, int n, int *count_p);

int main(){
  int i = 0;
  int count_p = 0;
  ifstream ind("input.txt");
  vector<point> points_xy;
  while (!ind.eof()){
      points_xy.push_back(point());
      ind >> points_xy[i].x >> points_xy[i].y;
      i++;
  }
  ind.close();
  cout << "Convex Hull is:" << endl;
  convex_hull(points_xy , --i, &count_p);
  qsort(&shell[0], count_p, sizeof(point), sort2);
  for (int i = 0; i < count_p; i += 2)
      cout << shell[i].x << " " << shell[i].y << endl;
  return 0;
}

void convex_hull(vector<point> xy, int n, int *count_p){
  int min_left = 0, max_right = 0;
  for (int i = 1; i < n; ++i){
    if (xy[i].x > xy[max_right].x)
      max_right = i;
    if (xy[i].x < xy[min_left].x)
      min_left = i;
    
  }
  build(xy, 1, min_left, max_right, n, count_p);
  build(xy, -1, min_left, max_right, n, count_p);
}

void build(vector<point> &xy, int pos, int min_left, int max_right, int n, int *count_p){
  int max = 0, flag = -1;
  for (int i = 0; i < n; ++i){
    if (dist(xy[min_left], xy[max_right], xy[i]) > max && pos_two_point(xy[min_left], xy[max_right], xy[i]) == pos){
      max = dist(xy[min_left], xy[max_right], xy[i]);
      flag = i;
    }
  }
  
  if (flag == -1){
    shell.push_back(xy[min_left]);
    shell.push_back(xy[max_right]);
    *count_p += 2;
    return;
  }
  build(xy, pos_two_point(xy[flag], xy[max_right], xy[min_left]) * (-1), flag, max_right, n, count_p);
  build(xy, pos_two_point(xy[flag], xy[min_left], xy[max_right]) * (-1), flag, min_left, n, count_p);
}

int dist(point point_1, point point_2, point point_3){
    int edge1 = (point_3.y - point_1.y) * (point_2.x - point_1.x);
    int edge2 = (point_2.y - point_1.y) * (point_3.x - point_1.x);
    if ((edge1 - edge2) < 0)
      return -(edge1 - edge2);
    return (edge1 - edge2);
}

int pos_two_point(point point_1, point point_2, point point_3){
    int edge1 = (point_3.y - point_1.y) * (point_2.x - point_1.x);
    int edge2 = (point_2.y - point_1.y) * (point_3.x - point_1.x);
    int a = (edge1 - edge2);
    if (a > 0)
        return -1;
    else if (a == 0) 
        return 0; 
    else 
        return 1;
}

int sort2(const void *one, const void *two){
    point *point_o = (point *)one;
    point *point_t = (point *)two;
    if (point_o->y < point_t->y && point_o->x == point_t->x)
        return -1;
    else if (point_o->x < point_t->x)
        return -1;
    else 
        return 1;
}