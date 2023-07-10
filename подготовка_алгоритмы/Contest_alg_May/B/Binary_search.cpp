#include <iostream>
using namespace std;

class Tree_elem {
    public:
        int elem_data;
        Tree_elem* left;
        Tree_elem* right;
        Tree_elem(int elem) {
            elem_data = elem;
            left = right = nullptr;
        }
};

Tree_elem* deleteTree(Tree_elem* root);
Tree_elem* deleteElemT(Tree_elem* root, int val);
Tree_elem* addElem(int, Tree_elem*);
void binSearch(const Tree_elem* root);
void findMax(const Tree_elem* root);
void findMin(const Tree_elem* root);
void preSuc(Tree_elem* root, Tree_elem*& pre, Tree_elem*& suc, int key);

int main() {
    int n = 0, el = 0;
    cin >> n;
    Tree_elem* rootHead = nullptr;
    for (int i = 0; i < n; ++i) {
        cin >> el;
        rootHead = addElem(el, rootHead);
    }
    binSearch(rootHead);
    int del_elem = 0;
    cin >> del_elem;
    rootHead = deleteElemT(rootHead, del_elem);
    cout << endl;
    binSearch(rootHead);
    cout << endl;
    findMax(rootHead);
    findMin(rootHead);

    Tree_elem* pre = nullptr, *suc = nullptr;
    int preSuc_elem = 0;
    cin >> preSuc_elem;
    preSuc(rootHead, pre, suc, preSuc_elem);
    if (pre != nullptr) cout << "Predecessor is " << pre->elem_data << endl;
    else                cout << "No Predecessor";
    if (suc != nullptr) cout << "Successor is " << suc->elem_data;
    else                cout << "No Successor";

    rootHead = deleteTree(rootHead);
    return 0;
}

Tree_elem* addElem(int elem, Tree_elem* root) {
    if (!root)
        root = new Tree_elem(elem);
    else {
        if (elem < root->elem_data)
            root->left = addElem(elem, root->left);
        else
            root->right = addElem(elem, root->right);
    }
    return root;
}

void binSearch(const Tree_elem* root) {
    if (root) {
        binSearch(root->left);
        cout << root->elem_data << " ";
        binSearch(root->right);
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

void swap(Tree_elem** root, int* elem) {
    if ((*root)->left)  swap(&(*root)->left, elem);
    *elem = (*root)->elem_data;
    Tree_elem* oldElem = *root;
    *root = (*root)->right;
    free(oldElem);
}

Tree_elem* deleteElem(Tree_elem* root) {
    if (!root->left && !root->right) {
        free(root);
        return  nullptr;
    }
    if (root->left && root->right) {
        int new_elem = 0;
        swap(&root->right, &new_elem);
        root->elem_data = new_elem;
        return root;
    }
    if (root->left && !root->right) {
        Tree_elem* old_elem = root->left;
        free(root);
        return old_elem;
    }
    if (!root->left && root->right) {
        Tree_elem* old_elem = root->right;
        free(root);
        return old_elem;
    }
    return nullptr;
}

Tree_elem* deleteElemT(Tree_elem* root, int del_elem) {
    if (root) {
        if (del_elem > root->elem_data)
            root->right = deleteElemT(root->right, del_elem);
        else if (del_elem < root->elem_data)
            root->left = deleteElemT(root->left, del_elem);
        else root = deleteElem(root);
    }
    return root;
}

void findMax(const Tree_elem* root) {
    if (root->right)
        findMax(root->right);
    else
        cout << root->elem_data << endl;
}

void findMin(const Tree_elem* root) {
    if (root->left)
        findMin(root->left);
    else
        cout << root->elem_data << endl;
}

void preSuc(Tree_elem* root, Tree_elem*& pre, Tree_elem*& suc, int elem) {
    if (root == nullptr)  return;
    if (root->elem_data == elem) {
        if (root->left != nullptr) {
            Tree_elem* needElemePre = root->left;
            while (needElemePre->right) needElemePre = needElemePre->right;
            pre = needElemePre ;
        }
        if (root->right != nullptr) {
            Tree_elem* needElemeSuc = root->right ;
            while (needElemeSuc->left) needElemeSuc = needElemeSuc->left ;
            suc = needElemeSuc ;
        }
        return ;
    }

    if (root->elem_data > elem) {
        suc = root ;
        preSuc(root->left, pre, suc, elem) ;
    } else {
        pre = root ;
        preSuc(root->right, pre, suc, elem) ;
    }
}