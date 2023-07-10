#pragma once

typedef struct Node {
	int data;
	struct Node* left, *right;
}NODE;

NODE* add_to_tree(NODE* root, int val);
void symmetric(const NODE* root);
void print_on_left_side(const NODE* root, int level);
NODE* delete_tree(NODE* root);
NODE* delete_from_tree(NODE* root, int val);