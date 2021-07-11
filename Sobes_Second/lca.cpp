// Есть дерево(содержит указатель на отца и на двух сыновей).
// Нужно описать node* lca(node *root, node *p, node *q)
// которая возвращает ближайшего общего отца(предка)
// Рассказать решение, сказать асимптотику полученного алгоритма,
// написать решение
// Использовать о(1) по памяти
// Lowest Common Ancesator (ближайщий общий предок)

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>

struct node {
	int value;
	node *left;
	node *right;
	node(int v): value(v), left(nullptr), right(nullptr) {}
};

node* lca(node *root, node *p, node *q) {
	if(root == NULL)
		return NULL;

	node * left = lca(root->left, p, q);

	if(root == p || root == q)
		return root;

	node * right = lca(root->right, p, q);

	if(left == NULL && right == NULL)
		return NULL;
	else if(left != NULL && right == NULL)
		return left;
	else if(left == NULL && right != NULL)
		return right;

	return root;
}
