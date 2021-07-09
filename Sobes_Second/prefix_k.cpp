// Для двух массивов целых чисел длины N, для всех
// K от 1 до N, посчитать количество общих чисел на префиксах длины K

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>
#include <unordered_map>


std::vector<int>	prefix_k(std::vector<int> & a, std::vector<int> & b, int k) {
	size_t len_a = a.size(), len_b = b.size(), ans = 0, i = 0;
	std::unordered_map<int, int> hash;
	std::vector<int> res;

	while (i < len_a && i < len_b) {
		if (i == k)
			res.push_back(ans);
		if (i > k)
			res.push_back(ans);

		if (hash.find(a[i]) != hash.end()) {
			if (hash[a[i]] < 0) {
				++ans;
			}
			++hash[a[i]];
		}
		else
			++hash[a[i]];

		if (hash.find(b[i]) != hash.end()) {
			if (hash[b[i]] > 0) {
				++ans;
			}
			--hash[b[i]];
		}
		else
			--hash[b[i]];

		++i;
	}

	if (i > k)
			res.push_back(ans);

	return res;
}

int main() {
	std::vector <int> a = {1, 2, 3, 0, 8, 5, 0};
	std::vector <int> b = {2, 0, 3, 5, 5};
	std::vector <int> res = prefix_k(a, b, 4);

	for (auto it : res)
		std::cout << it << " "; // 3 3
}