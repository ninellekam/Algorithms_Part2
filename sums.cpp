#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int	FindConvMinSum(std::vector <int> & vec, int k) {
	std::unordered_map <int, int> Set;
	size_t i = 0, j = 0, len = vec.size();
	int min_sum = INT_MAX, sum = 0;

	while (i < len) {
		if (vec[i] <= k) {
				++Set[vec[i]];
				std::cout << " IN " << vec[i] << "\n";
		}
		sum += vec[i];
		if (Set.size() == k) {
			if (sum < min_sum) {
				min_sum = sum;
				std::cout << "\n!!!!!!!!!!!!!!!!!!MIN SUM " << min_sum << "\n";
			}

			while (Set.size() == k) {
				std::cout << sum << "";
				sum -= vec[j];

				if (vec[j] <= k) {
					--Set[vec[j]];
					if (Set[vec[j]] == 0) {
						Set.erase(vec[j]);
						for (auto it : Set)
							std::cout << " ELEMENT " << it.first << " ";
					}
				}

				std::cout << " - " << vec[j] << " = " << sum << " \n";
				if (Set.size() == k)
					if (sum < min_sum) {
						min_sum = sum;
						std::cout << "\nMIN SUM " << min_sum << "\n";
					}
				++j;
			}
		}
		++i;
	}
	std::cout << "\nanswer is a " << min_sum << "!!!!\n";
	return min_sum;
}

int main() {
	std::vector <int> vec = {1, 2,2, 3, 5, 0, 0};
	FindConvMinSum(vec, 3);
}