// BinTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };



class node {
public:
	void insert_integer( node*& tree, int value);
	void print_tree( node* tree);
	void terminate_tree( node* tree);
	

protected:
	int value;
	node* left;
	node* right;
};

node* root = nullptr;
/*struct node {
	int value;
	struct node* left;
	struct node* right;
	
};

struct node* root = nullptr;

// implement the functions described by these headers
void insert_integer(struct node*& tree, int value);
void print_tree(struct node* tree);
void terminate_tree(struct node* tree);
*/

void node::insert_integer( node*& tree, int value) {
		if (tree == nullptr) {
			tree = new node();
			
			tree->left = nullptr;
			tree->right = nullptr;
			tree->value = value;
		}
		else {
			if (tree->value == value) {
				return;
			}
			if (value > tree->value) {
				insert_integer(tree->right, value);
			}
			else if(value < tree->value) {
				insert_integer(tree->left, value);
			}
		}
	}


void node::print_tree( node* tree) {
	if (tree == nullptr) {
		return;
	}
	else {
		print_tree(tree->left);
		cout << tree->value << endl;
		print_tree(tree->right);
	}
}

void node::terminate_tree( node* tree) {
	if (tree == nullptr) {
		return;
	}
	else {
		print_tree(tree->left);
		print_tree(tree->right);
		delete tree;
		tree = NULL;
	}
}



int main() {

	for (int i : arr) {
		int x = rand() % 10;
		swap(arr[i], arr[x]);
	}
	for (int i : arr) {
		cout << arr[i] << endl;
	}
	for (int i : arr){
		root->insert_integer(root, i);
	}

	root->print_tree(root);
	int x = 0;
	
	return 0;
}



