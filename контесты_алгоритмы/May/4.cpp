#include <iostream>
#include <vector>
using namespace std;

class Tree_elem {
public:
    int color;
    int pos;
    int higher;

    Tree_elem* left;
    Tree_elem* right;

    Tree_elem(int color_elem, int pos_elem, int higher_elem) {
        color = color_elem;
        higher = higher_elem;
        pos = pos_elem;
        left = right = nullptr;
    }
};

Tree_elem* deleteTree(Tree_elem* root);
Tree_elem* addElem(vector<vector<int>> &array, int, Tree_elem*, int higher, int &max_higher);
int find_start(vector<int> start);
void check(const Tree_elem* root, int max_higher);

int main() {
    int n = 0,
        count_elem = 0;
    Tree_elem* rootHead = nullptr;
    vector<vector<int>> arrayVer;
    cin >> n;
    vector<int> start(n,0);

    for (int i = 0; i < n; i++) {
        cin >> count_elem;
        if (count_elem > 2) {
            cout << "NO";
            exit(EXIT_SUCCESS);
        }
        vector<int> new_elem = {-1, -1, 0};
        for (int j = 0; j < count_elem; j++) {
            int pos_elem = 0; cin >> pos_elem;
            start[pos_elem] = 1;
            new_elem[j] = pos_elem;
        }
        int color = 0; cin >> color;
        new_elem[2] = color;
        arrayVer.push_back(new_elem);
    }
    int pos_start = find_start(start);
    if (arrayVer[pos_start][2] == 1) {
        cout << "NO";
        exit(EXIT_SUCCESS);
    }
    int max_higher = 0;
    rootHead = addElem(arrayVer, pos_start, rootHead, 0, max_higher);
    check(rootHead, max_higher);
    cout << "YES";
    deleteTree(rootHead);
    return 0;
}

int find_start(vector<int> start) {
    for (int i = 0; i < start.size(); i++) {
        if (start[i] == 0) {
            return i;
        }
    }
    return -1;
}

Tree_elem* addElem(vector<vector<int>> &array, int pos_elem, Tree_elem* root, int higher, int &max_higher) {
    if (pos_elem != -1) {
        if (array[pos_elem][2] == 0)
            higher++;
        root = new Tree_elem(array[pos_elem][2], pos_elem, higher);
        root->left = addElem(array, array[pos_elem][0], root->left, higher, max_higher);
        root->right = addElem(array, array[pos_elem][1], root->right, higher, max_higher);
    } else {
        higher++;
        if (max_higher < higher)
            max_higher = higher;
        root = new Tree_elem(0, -1, higher);
    }
    return root;
}

Tree_elem* deleteTree(Tree_elem* root) {
    if (root) {
        root->right = deleteTree(root->right);
        root->left = deleteTree(root->left);
        free(root);
    }
    return nullptr;
}

void check(const Tree_elem* root, int max_higher) {
    if (root && root->pos != -1) {
        if (root->color == 1) {
            if (root->left->color == 0 && root->right->color == 0) {
                check(root->right, max_higher);
                check(root->left, max_higher);
            } else {
                cout << "NO";
                exit(EXIT_SUCCESS);
            }
        }
        check(root->right, max_higher);
        check(root->left, max_higher);
    } else if (root->pos == -1) {
        if (max_higher != root->higher) {
            cout << "NO";
            exit(EXIT_SUCCESS);
        }
    }
}