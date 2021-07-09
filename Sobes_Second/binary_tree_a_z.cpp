// Дано бинарное дерево с выделенным корнем, в каждой вершине которого записано [A-Z].
// Две вершины считаются эквивалентными,
// если поддеревья этих вершин содержат одинаковое множество (т.е без учета частот букв)


#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>

std::unordered_set<char> st;

struct node {
	char value;
	node * left;
	node * right;
	node(char x): value(x), left(nullptr), right(nullptr) {}
};

int	answer_get(node *a, node *b, std::unordered_map<char, int> & hash, int &ans) {

	if (a == nullptr && b == nullptr)
		return ans;

	if ((a == nullptr || b == nullptr) {
		ans = -1;
		return ans;
	}

	if (hash[a->value] < 0)
		if (st.find(a->value) == st.end()) {
			++ans;
			st.insert(a->value);
		}

	++hash[a->value];

	if (hash[b->value] > 0)
		if (st.find(b->value) == st.end()) {
			++ans;
			st.insert(b->value);
		}

	--hash[b->value];


	answer_get(a->left, b->left, hash, ans);
	answer_get(a->right, b->right, hash, ans);

	return ans;
}

bool	eqvivalent(node *a, node *b) {
	std::unordered_map<char, int> hash;
	int ans = 0;
	int res = answer_get(a, b, hash, ans);

	// std::cout << " res " << res << " ";
	if (res == hash.size())
		return true;

	return false;
}

int main() {
	node *root = new node('a');

	root->left = new node('b');
	root->right = new node('b');

	root->left->left = new node('c');
	root->left->right = new node('j');

	root->right->left = new node('c');
	root->right->right = new node('j');

	std::cout << eqvivalent(root->left, root->right);
}