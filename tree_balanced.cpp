#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

struct TreeNode {
	int v;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : v(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
		if(nums.empty())
			return NULL;

		if(nums.size() == 1){
			TreeNode* root = new TreeNode(nums[0]);
			return root;
		}

		int mid = nums.size() / 2;
		TreeNode* root = new TreeNode(nums[mid]);

		std::vector<int> left(nums.begin(), nums.begin() + mid);
		std::vector<int> right(nums.begin() + mid + 1, nums.end());

		root->left = sortedArrayToBST(left);
		root->right = sortedArrayToBST(right);

		return root;
	}

void print_tree(TreeNode *root) {
	if (root == NULL)
		return;
	print_tree(root->left);
	std::cout << root->v;
	print_tree(root->right);
}

bool isLeaf(TreeNode* node) {
	return node->left == nullptr && node->right == nullptr;
}

void TestOne() {
	std::vector<int> vec = {1};
	TreeNode* head = sortedArrayToBST(vec);
	assert(head->v == 1);
	assert(isLeaf(head));
}

void TestSmall() {
		std::vector<int> vec = {1, 2, 3};
		TreeNode* head = sortedArrayToBST(vec);
		assert(head->v == 2);

		assert(head->left->v == 1);
		assert(isLeaf(head->left));

		assert(head->right->v == 3);
		assert(isLeaf(head->right));
}

void TestSmall1() {
	std::vector<int> vec = {-3, -2, -1};
	TreeNode* head = sortedArrayToBST(vec);
	assert(head->v == -2);

	assert(head->left->v == -3);
	assert(isLeaf(head->left));

	assert(head->right->v == -1);
	assert(isLeaf(head->right));
}

void TestEqual() {
	std::vector<int> vec = {8, 8, 8};
	TreeNode* head = sortedArrayToBST(vec);
	assert(head->v == 8);

	assert(head->left->v == 8);
	assert(isLeaf(head->left));

	assert(head->right->v == 8);
	assert(isLeaf(head->right));
}

void TestMinus() {
	std::vector<int> vec = {-8, 8, 8};
	TreeNode* head = sortedArrayToBST(vec);
	assert(head->v == 8);

	assert(head->left->v == -8);
	assert(isLeaf(head->left));

	assert(head->right->v == 8);
	assert(isLeaf(head->right));
}

int main() {
	std::vector<int> vec = {-8, 8, 8};
	TreeNode* root = sortedArrayToBST(vec);
	print_tree(root);
	// TestOne();
	// std::cout << "OK!\n";
	// TestSmall();
	// std::cout << "OK!\n";
	// TestSmall1();
	// std::cout << "OK!\n";
	// TestEqual();
	// std::cout << "OK!\n";
	// TestMinus();
	// std::cout << "OK!\n";

}