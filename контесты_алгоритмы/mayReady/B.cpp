#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Heap {
public:
    vector<pair<int, long long>> bin_heap;
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

    pair<int, long long> getMin() {
        return make_pair(bin_heap[0].first, bin_heap[0].second);
    }

    void insert(int value) {
        bin_heap[size_heap].second = value;
        sift_up(size_heap);
        size_heap++;
    }

    void sift_up(int i) {
        if (i == 0)
            return;
        int parent = get_parend(i);
        if (bin_heap[i] < bin_heap[parent]) {
            swap(bin_heap[i], bin_heap[parent]);
            sift_up(parent);
        }
    }

    void sift_down(int parent) {
        int left = get_left_children(parent);
        int right = get_right_children(parent);
        int find_min_elem = parent;
        if  (left < size_heap && ( bin_heap[left].second < bin_heap[parent].second ||
                                 ( bin_heap[left].first < bin_heap[parent].first && bin_heap[left].second == bin_heap[parent].second ) ) )
            find_min_elem = left;
        if (right < size_heap && ( bin_heap[left].second > bin_heap[right].second ||
                                 ( bin_heap[left].first > bin_heap[right].first && bin_heap[left].second == bin_heap[right].second ) ) )
            find_min_elem = right;
        if ( ( ( bin_heap[parent].second == bin_heap[find_min_elem].second && bin_heap[parent].first > bin_heap[find_min_elem].first ) ||
                 bin_heap[parent].second > bin_heap[find_min_elem].second) && parent != find_min_elem) {
            swap(bin_heap[find_min_elem], bin_heap[parent]);
            sift_down(find_min_elem);
        }
    }

    pair<int, long long> delete_min() {
        if (size_heap == 0)
            return make_pair(-1, -1);
        swap(bin_heap[0], bin_heap[size_heap - 1]);
        size_heap--;
        sift_down(0);
        return make_pair(bin_heap[size_heap].first, bin_heap[size_heap].second);
    }
};

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    Heap bin_h(n);
    for (int i = 0; i < n; i++) {
        bin_h.bin_heap[bin_h.size_heap].first = i;
        bin_h.bin_heap[bin_h.size_heap].second = 0;
        bin_h.size_heap++;
    }
    for (int i = 0; i < m; i++) {
        long long get_p = 0;
        cin >> get_p;
        pair<int, long long> p = bin_h.getMin();
        cout << p.first << " " << p.second << endl;
        bin_h.bin_heap[0].second += get_p;
        bin_h.sift_down(0);
    }
    return 0;
}
