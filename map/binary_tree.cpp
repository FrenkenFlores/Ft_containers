#include <iostream>
#include <cstdbool>

struct node {
	int data;
	node *left;
	node *right;
};

node *create_node(const int data) {
	node *n = new(node);
	n->left = nullptr;
	n->right = nullptr;
	n->data = data;
	return n;
}

bool insert_node(node **root, int const data) {
	if (*root == NULL) {
		*root = create_node(data);
		return true;
	}
	if ((*root)->data == data)
		return false;
	if ((*root)->data > data) {
		return insert_node(&(*root)->left, data);
	} else {
		return insert_node(&(*root)->right, data);
	}
}

bool find_node(const node *root, const int data) {
	if (root == NULL)
		return false;
	if (root->data == data)
		return true;
	if (root->data > data)
		return find_node(root->left, data);
	else
		return find_node(root->right, data);
	return false;
}

void print_tree(node *root, int level = 0) {
	if (root == NULL) {
		for(int i = 0; i < level; i++) std::cout << '\t';
		std::cout << "leaf" << std::endl;
		return;
	}
	for(int i = 0; i < level; i++) std::cout << '\t';
	std::cout << root->data << std::endl;

	for(int i = 0; i < level; i++) std::cout << '\t';
	std::cout << "left" << std::endl;
	print_tree(root->left, level + 1);

	for(int i = 0; i < level; i++) std::cout << '\t';
	std::cout << "right" << std::endl;
	print_tree(root->right, level + 1);
}

int main() {
	node *root = NULL;
	insert_node(&root, 10);
	insert_node(&root, 0);
	insert_node(&root, 1);
	insert_node(&root, 15);
	insert_node(&root, 11);
	print_tree(root);
	std::cout << "10: " << find_node(root, 10) << std::endl;
	std::cout << "500: " << find_node(root, 500) << std::endl;
	return (0);
}



