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
void inOrder(const Tree_elem* root);
void preOrder(const Tree_elem* root);
void postOrder(const Tree_elem* root);

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

    inOrder(rootHead);
    cout << endl;
    preOrder(rootHead);
    cout << endl;
    postOrder(rootHead);
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

void inOrder(const Tree_elem* root) {
    if (root) {
        inOrder(root->left);
        cout << root->elem_data << " ";
        inOrder(root->right);
    }
}

void preOrder(const Tree_elem* root) {
    if (root) {
        cout << root->elem_data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(const Tree_elem* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->elem_data << " ";
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