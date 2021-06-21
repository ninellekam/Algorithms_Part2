#include <iostream>
#include <vector>
#include <unordered_map>

int	FindConvMinSum(std::vector <int> & vec, int k) {
	std::unordered_map <int, int> Set;
	size_t i = 0, j = 0, len = vec.size();
	int min_sum = INT_MAX, sum = 0;

	while (i < len) {
		if (vec[i] <= k)
				++Set[vec[i]];

		sum += vec[i];

		if (Set.size() == k) {
			if (sum < min_sum)
				min_sum = sum;

			while (Set.size() == k) {
				sum -= vec[j];

				if (vec[j] <= k) {
					--Set[vec[j]];
					if (Set[vec[j]] == 0)
						Set.erase(vec[j]);
				}

				if (Set.size() == k)
					if (sum < min_sum)
						min_sum = sum;

				++j;
			}
		}
		++i;
	}
	std::cout << min_sum ;
	return min_sum;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int cnt_elems, vec_elems, k = 3;
	// std::vector <int> vec;
	// std::cin >> cnt_elems;

	// for(size_t i = 0; i < cnt_elems; ++i) {
	// 	std::cin >> vec_elems;
	// 	vec.push_back(vec_elems);
	// }
	// std::cin >> cnt_elems;

// for simple:
	std::vector <int> vec = {2, 2, 2, 1, 3, 1, 1, 1, 1, 1};
	FindConvMinSum(vec, k);
}