#include <iostream>
#include <vector>
using namespace std;

class Tree_elem {
public:
    int elem_data;
    int pos;
    Tree_elem* left;
    Tree_elem* right;
    Tree_elem(int elem, int pos_elem) {
        pos = pos_elem;
        elem_data = elem;
        left = right = nullptr;
    }
};

Tree_elem* deleteTree(Tree_elem* root);
Tree_elem* addElem(vector<vector<int>> &array, int, Tree_elem*);
void inOrder(const Tree_elem* root, vector<int> &new_array);

int main() {
    int n = 0, key = 0, left = 0, right = 0;
    Tree_elem* rootHead = nullptr;
    cin >> n;
    vector<vector<int>> array;
    for (int i = 0; i < n; ++i) {
        cin >> key >> left >> right;
        array.push_back({key, left, right});
    }

    rootHead = addElem(array, 0, rootHead);
    vector<int> new_array;
    int flag = 0;
    inOrder(rootHead, new_array);
    for (int i = 0; i < n - 1; i++) {
        if (new_array[i] > new_array[i + 1])
            flag = 1;
    }
    if (flag == 1)
        cout << "INCORRECT";
    else
        cout << "CORRECT";
    deleteTree(rootHead);
    return 0;
}

Tree_elem* addElem(vector<vector<int>> &array, int pos_elem, Tree_elem* root) {
    if (pos_elem != -1) {
        root = new Tree_elem(array[pos_elem][0], pos_elem);
        root->left = addElem(array, array[pos_elem][1], root->left);
        root->right = addElem(array, array[pos_elem][2], root->right);
    }
    return root;
}

void inOrder(const Tree_elem* root, vector<int> &new_array) {
    if (root) {
        inOrder(root->left, new_array);
        new_array.push_back(root->elem_data);
        inOrder(root->right, new_array);
    }
}


Tree_elem* deleteTree(Tree_elem* root) {
    if (root) {
        root->right = deleteTree(root->right);
        root->left = deleteTree(root->left);
        free(root);
    }
    return nullptr;
}