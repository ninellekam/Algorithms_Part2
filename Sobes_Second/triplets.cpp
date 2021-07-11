#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <climits>


std::vector<int>	triplets(std::vector <int> & a, std::vector <int> & b, std::vector <int> & c, int target) {
	int r = 0, l = 0, k = 0;
	size_t len_a = a.size(),  len_b = b.size(), len_c = c.size();
	std::vector<int> answer;

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	std::sort(c.begin(), c.end());

	for (int k = 0; k < len_c; ++k) {
		l = 0;
		r = len_b - 1;
		while (l < len_a && r >= 0) {
			int sum = a[l] + b[r];

			int diff = target - sum;

			if (diff == c[k]) {
				answer.push_back(l), answer.push_back(r), answer.push_back(k);
				return answer;
			}

			if (sum > diff)
				--r;
			if (sum < diff)
				++l;
			if (sum == diff)
				return answer;
		}
	}

	return answer;
}

int main() {
	std::vector <int> a = {1, 1, 2, 8, 8, 10};
	std::vector <int> b = {0, 0, 6, 7, 8, 8};
	std::vector <int> c = {2, 4, 9, 10, 11, 17};

	std::vector <int> res = triplets(a, b, c, 17);

	std::cout <<  "\nANSWER ";
	for (auto it : res)
		std::cout << it << " ";
}