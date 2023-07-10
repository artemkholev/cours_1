#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Heap {
public:
    vector<int> bin_heap;
    vector<pair<int, int>> save_info;
    int max_size_heap;
    int size_heap;

    Heap(int size) {
        max_size_heap = size;
        size_heap = 0;
        bin_heap.resize(max_size_heap);
    }

    int get_left_children(int i) {
        return (2 * i + 1);
    }
    int get_right_children(int i) {
        return (2 * i + 2);
    }
    int get_parend(int i) {
        return floor((i - 1) / 2);
    }

    int getMin() {
        return bin_heap[0];
    }

    void insert(int value) {
        bin_heap[size_heap] = value;
        sift_up(size_heap);
        size_heap++;
    }

    void sift_up(int i) {
        if (i == 0)
            return;
        int parent = get_parend(i);
        if (bin_heap[i] < bin_heap[parent]) {
            save_info.push_back({parent, i});
            swap(bin_heap[i], bin_heap[parent]);
            sift_up(parent);
        }
    }

    void sift_down(int parent) {
        int left = get_left_children(parent);
        int right = get_right_children(parent);
        int find_min_elem = parent;
        if  (left < size_heap && bin_heap[left] < bin_heap[parent])
            find_min_elem = left;
        if (right < size_heap && bin_heap[left] > bin_heap[right])
            find_min_elem = right;
        if (bin_heap[parent] > bin_heap[find_min_elem] && parent != find_min_elem) {
            save_info.push_back({parent, find_min_elem});
            swap(bin_heap[find_min_elem], bin_heap[parent]);
            sift_down(find_min_elem);
        }
    }

    int delete_min() {
        if (size_heap == 0)
            return -1;
        swap(bin_heap[0], bin_heap[size_heap - 1]);
        size_heap--;
        sift_down(0);
        return bin_heap[size_heap];
    }
};

int main() {
    int n = 0;
    cin >> n;
    Heap bin_h(n);
    for (int i = 0; i < n; i++) {
        int take_elem = 0;
        cin >> take_elem;
        bin_h.bin_heap[bin_h.size_heap] = take_elem;
        bin_h.size_heap++;
    }
    for (int i = (n)  ; i >= 0; i--) {
        bin_h.sift_down(i);
    }
    int size = bin_h.save_info.size();
    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cout << bin_h.save_info[i].first << " " << bin_h.save_info[i].second << endl;
    }
    return 0;
}
