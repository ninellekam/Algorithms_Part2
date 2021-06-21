#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

int	FindConvMinSum(std::vector <int> & vec, int k) {
	std::unordered_set <int> Set;
	size_t i = 0, j = 0, len = vec.size();
	int min_sum = INT_MAX, sum = 0;

	while (i < len) {
		if (vec[i] <= k) {
			if (Set.find(vec[i]) == Set.end()) {
				Set.insert(vec[i]);
			}
		}
		sum += vec[i];
		if (Set.size() == k) {
			if (sum < min_sum)
				min_sum = sum;

			while (j < i) {
				std::cout << sum << " ";
				sum -= vec[j];

				if (vec[j] <= k)
					Set.erase(vec[j]);

				std::cout << " - " << vec[j] << " = " << sum << " \n";
				if (Set.size() == k)
					if (sum < min_sum) {
						min_sum = sum;
						std::cout << "MIN SUM " << min_sum << "\n";
					}
				++j;
			}
		}
		++i;
	}
	std::cout << "\nanswer is a " << min_sum << "\n";
	return min_sum;
}

int main() {
	std::vector <int> vec = {1, 2, 5, 6, 4, 3, 2, 1};
	FindConvMinSum(vec, 3);
}