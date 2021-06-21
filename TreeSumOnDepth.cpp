#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>

class TreeNode {
public:
	int v;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : v(x), left(NULL), right(NULL) {}
};

void free_root(TreeNode *root) {
		if (root == NULL)
			return ;

		free_root(root->right);
		free_root(root->left);

		if (root != NULL) {
			free(root);
		}
	}

int TreeSum(TreeNode *root, int depth) {
	if (root == NULL)
		return 0;

	if (depth == 1)
		return root->v;

	return TreeSum(root->left, depth - 1) + TreeSum(root->right, depth - 1);
}

void print(TreeNode *root) {
	if (root == NULL)
		return;
	print(root->left);
	print(root->right);
	std::cout << root->v << "\n";
}


int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	std::cout << (TreeSum(root, 3));

	free_root(root);
}