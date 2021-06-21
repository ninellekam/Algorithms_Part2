#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>

std::vector <int> Arrays(std::vector <int> &a, std::vector <int> &b) {
	size_t i = 0, j = 0;
	size_t len1 = a.size(), len2 = b.size();
	std::vector <int> vec_return;

	while (i < len1 && j < len2) {
		if (a[i] < b[j]) {
			vec_return.push_back(a[i]);
			++i;
		}
		if (a[i] > b[j])
			++j;
		if (a[i] == b[j]) {
			++i;
			++j;
		}
	}
	while (i < len1) {
		vec_return.push_back(a[i]);
		++i;
	}

	return vec_return;
}

int main() {
	std::vector <int> a = {5, 5, 5, 6, 7, 8, 8, 9, 11};
	std::vector <int> b = {2, 2, 5, 5, 6, 7, 8, 9, 10};

	std::vector <int> ret = Arrays(a, b);
	for (auto it : ret)
		std::cout << it << "\n";
}