#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
  int data;
  struct Node *left, *right;
}NODE;

NODE* add_to(NODE* root, int value){
  if (!root){
    root = (NODE*)malloc(sizeof(NODE));
    root->data = value;
    root->left = root->right = NULL;  
  }
  else{
    if(root->data > value){
      root->left = add_to(root->left, value);
    }
    else{
      root->right = add_to(root->right, value);
    }
  }
  return root;
}

NODE* delete_graph(NODE* root){
  if(root){
    root->left = delete_graph(root->left);
    root->right = delete_graph(root->right);
    free(root);
  }
  return NULL;
}

void replace(NODE** root, int* val){ 
  if((*root)->left)
    replace(&(*root)->left, val);
  *val = (*root)->data;
  //*root = del_el(*root);
  if (!(*root)->right)
    free(*root);
  else{
    NODE* temp = (*root)->right;
    free(*root);
    (*root)->left = temp;
  }
} 

NODE* del_el(NODE* root){
  if (!root->left && !root->right){
    free(root);
    return NULL;
  }
  if (root->left && !root->right){
    NODE* temp = root->left;
    free(root);
    return temp;
  }
  if (!root->left && root->right){
    NODE* temp = root->right;
    free(root);
    return temp;
  }
  if(root->left && root->right){
    int a = 0;
    replace(&root->right, &a);
    root->data = a;
    return root;
  }
}

void symmetric(const NODE *root){
  if (root){
    symmetric(root->left);
    printf("%d ", root->data);
    symmetric(root->right);
  }
}

void print_graph(const NODE* root, int level){
  if(root){
    print_graph(root->right, level + 1);
    for (int i = 0; i < level; i++){
      printf("\t");
    }
    printf(" %d \n", root->data);
    print_graph(root->left, level + 1);
  }
}

NODE* delete_element(NODE* root, int value){
  if(root){
    if(root->data > value){
      delete_element(root->left, value);
    }
    else if(root->data < value){
      delete_element(root->right, value);
    }
    else
      root = del_el(root);
  }
  return root;
}

int main(){
  int n = 3;
  int a = 0;
  NODE *root = NULL;
  srand((unsigned int)time(NULL));
  for (int i = 0; i < n; i++){
    //root = add_to(root, rand() % 201 - 100);
    scanf("%d", &a);
    root = add_to(root, a);
  }
  symmetric(root);
  printf("\n\n");
  print_graph(root, 0);
 
  scanf("%d", &a);
  root = delete_element(root, a);
  symmetric(root);
  
  root = delete_graph(root);
  return 0;
}