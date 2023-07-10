#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define TEXT

// backpack
#ifdef TEXT_1

void find_answer(vector<vector<int>>&array, int n, int w, vector<int>&mm){
  if (array[n][w] == 0)
    return;
  else if (array[n - 1][w] == array[n][w])
    find_answer(array, n - 1, w, mm);
  else {
    find_answer(array, n - 1, w - mm[n - 1], mm);
    cout << n << endl;
  }
}

int main(){
  int n = 5 + 1, w = 13;
  vector <int> waight = {3, 4, 5, 8, 9}; 
  vector <int> price = {1, 6, 4, 7, 6};
  vector <vector<int>> array(n, vector <int> (w, 0));

  // for (int i = 0; i < w; i++){
  //   array[0][i] = 0;
  // }
  // for (int i = 0; i < n; i++){
  //   array[i][0] = 0;
  // }

  for (int i = 1; i < n; ++i){
    for (int j = 1; j < w; ++j){
      if (j >= waight[i - 1]){
        array[i][j] = max(array[i-1][j], array[i-1][j-waight[i-1]] + price[i-1]);
      }
      else{
        array[i][j] = array[i - 1][j];
      }
    }
  }

  cout << "Pos thing, that we have max benefit" << endl;
  find_answer(array, n - 1, w - 1, waight);

  // for (int i = 0; i < n; i++){
  //   for (int j = 0; j < w; j++){
  //     cout << " " << array[i][j];
  //   }
  //   cout << "\n"
  // }
  return 0;
}
#endif

//longes_common_subsequence
#ifdef TEXT_2
int main(){
  string str1 = "bacad";
  string str2 = "accbadcb";
  int l1 = str1.size();
  int l2 = str2.size();
  vector<vector<int>> array(l1, vector<int>(l2, 0));
  for (int i = 0; i < l1; i++)
    array[i][0] = (str1[i] == str2[0]);
  for (int i = 0; i < l2; i++)
    array[0][i] = (str1[0] == str2[i]);

  for (int i = 1; i < l1; i++){
    for (int j = 1; j < l2; j++){
      array[i][j] = max(array[i - 1][j], array[i][j - 1]);
      if (str1[i - 1] == str2[j - 1]){
        array[i][j] = max(array[i][j], array[i - 1][j - 1] + 1);
      }
    }
  }

  cout << array[l1 - 1][l2 - 1] << endl;
  // for (int i = 0; i < l1; i++){
  //   for (int j = 0; j < l2; j++){
  //     cout << " " << array[i][j];
  //   }
  //   cout << "\n";
  // }
  return 0;
}
#endif

//the_maximum_sum_of_a_continuous_subsequence 
#ifdef TEXT_3
int main(){
  vector<int> array = {10, -100, -100, 15, 10};
  int len = array.size();
  int sum = 0, answer;
  for (int i = 0; i < len; i++){
    sum = max(0, sum + array[i]);
    answer = max(sum, answer);
  }
  cout << answer << endl;
  return 0;
}
#endif

//greed
#ifdef TEXT_4
int main(){
  int n = 0, p = 0;
  cin >> n;
  vector<int> array(n), pom(n);
  for (int i = 0; i < n; i++){
    cin >> array[i];
  }
  int pos = n - 1;
  pom[pos] = 1;

  for (int i = n - 2; i >= 0; i--){
    if (array[pos] >= array[i]){
      pom[pos] += 1;
    }
    else{
      pos = i;
      pom[pos] = 1;
    }
  }

  p = 0;
  for (int i = 0; i < n; i++){
    p += (array[i] * pom[i]);
  }
  cout << p << endl;
  return 0;
}
#endif

//convex hull

#ifdef TEXT
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





#endif

//48 10 50 19 34 1 36 20 26 29 61 48 0 8 45 4 78 31 74 16 41 29 8 34 43 8 75 34 25 38
//0 8 8 34 34 1 45 4 61 48 74 16 78 31
//7 35 52 45 96 1 8 33 99 7 80 29 97 17 63 41 62 44 95 12 92 19 69 18 72 19 78 30 67 25 39 9 34 38 84 48 67 17 32 43 69 32 48 1 8 8 33 2 38 7 83 18 99 7 49 18 28 26 75 28 75 7 75 10 52 17 60 16 32 44 14 46 33 50 77 38 36 23 60 32 62 11 6 25 28 22 46 5 20 15 9 16 21 2 40 28 9 22 35 18 25 25 6 33 19 17 1 9 81 39 18 28 58 36 7 29 57 4 62 45 81 3 55 30 58 43 52 39 22 14 4 23 81 5 1 22 73 50 17 44 76 36 64 27 97 18 11 36 79 27 90 26 55 22 75 31 41 45 9 4 55 42 29 19 71 35 91 37 80 26 11 11 55 12 42 15 78 47 5 20 47 15 96 42 45 38 23 42
//1 9 1 22 6 33 7 35 9 4 14 46 21 2 33 50 48 1 73 50 84 48 96 1 96 42 99 7


// point point_one;
// int sort(const void *one, const void *two);
// int sort2(const void *one, const void *two);
// int dist(point point_1, point point_2);
// void swap_point(point &point_1, point &point_2);
// point last(stack<point> &stack_point);
// int pos_two_point(point point_1, point point_2, point point_3);
// void basic(vector<point> xy, int n);
  
// int main(){
    
//     return 0;
// }

// void basic(vector<point> xy, int n){
//     stack<point> stack;
//     int min_meaning = xy[0].y, pos_min = 0;
//     int p = 1; 
//     for (int i = 1; i < n; ++i){
//         if ((xy[i].y < min_meaning)){
//             pos_min = i;
//             min_meaning = xy[i].y;
//         }
//         else if (((xy[pos_min].x > xy[i].x) && min_meaning == xy[i].y)){
//             pos_min = i;
//             min_meaning = xy[i].y;
//         }
//     }
//     swap_point(xy[0], xy[pos_min]);

//     point_one = xy[0];
//     qsort(&xy[1], n - 1, sizeof(point), sort);
//     for (int i = 1; i < n; ++i){
//         while (pos_two_point(point_one, xy[i], xy[i+1]) == 0 && n-1 > i)
//             ++i;
//         xy[p] = xy[i];
//         ++p;
//     }
//     for (int i = 0; i < 3; i++)
//         stack.push(xy[i]);
//     int pp = 3;
//     for (int i = 3; i < p; i++){
//         while ((stack.size() > 1) && pos_two_point(last(stack), stack.top(), xy[i]) != -1){
//            stack.pop();
//            pp--;
//         }
//         stack.push(xy[i]);
//         pp++;
//     }
//     int start = 0;
//     while (!stack.empty()){
//         xy[start++] = stack.top();;
//         stack.pop();
//     }
//     
// }

// int dist(point point_1, point point_2){
//     return (point_1.x - point_2.x)*(point_1.x - point_2.x) + (point_1.y - point_2.y)*(point_1.y - point_2.y);
// }
// void swap_point(point &point_1, point &point_2){
//     point point_copy = point_1;
//     point_1 = point_2;
//     point_2 = point_copy;
// } 
// int pos_two_point(point point_1, point point_2, point point_3){
//     int edge1 = (point_2.y - point_1.y) * (point_3.x - point_2.x);
//     int edge2 = (point_2.x - point_1.x) * (point_3.y - point_2.y);
//     int a = (edge1 - edge2);
//     if (a > 0)
//         return 1;
//     else if (a == 0) 
//         return 0; 
//     else 
//         return -1;
// }
// point last(stack<point> &stack_point){
//     point point_last = stack_point.top();
//     stack_point.pop();
//     point last = stack_point.top();
//     stack_point.push(point_last);
//     return last;
// }
// int sort(const void *one, const void *two){
//     int pos = 0;
//     point *point_o = (point *)one;
//     point *point_t = (point *)two;
//     pos = pos_two_point(point_one, *point_o, *point_t);
//     if (pos == 0){
//         if(dist(point_one, *point_t) >= dist(point_one, *point_o))
//             return -1;
//         else 
//             return 1;
//     }
//     if (pos == -1)
//         return -1;
//     else 
//         return 1;
// }
