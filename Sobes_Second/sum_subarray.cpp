// Дан массив целых чисел, нужно найти непустой
// подотрезок (непрерывную подпоследовательность) с заданной суммой X,
// либо сказать, что это невозможно.
// Для найденного отрезка (если он существует)
// следует выдать на выход индексы его концов.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>
#include <unordered_map>

std::pair<int, int> sum_subarray_negative(std::vector <int> & arr, int target) {
	std::unordered_map<int, int> map;
	size_t len = arr.size();

	int curr_sum = 0;

	for (int i = 0; i < len; i++) {
		curr_sum = curr_sum + arr[i];

		if (curr_sum == target) {
			return {0, i};
		}

		if (map.find(curr_sum - target) != map.end()) {
			return {map[curr_sum - target] + 1, i};
		}

		map[curr_sum] = i;
	}

	return {-1, -1};
}


// std::pair<int, int> sum_subarray_non_negative(std::vector <int> & vec, int target) {
// 	size_t len = vec.size();
// 	int  start, curr_sum;

// 	curr_sum = vec[0];
// 	start = 0;

// 	for(int i = 1; i < len; i++) {
// 		if (i < len)
// 			curr_sum += vec[i];

// 		while (curr_sum > target && start < i) {
// 			curr_sum = curr_sum - vec[start];
// 			std::cout << curr_sum << " ";
// 			++start;
// 		}

// 		if (curr_sum == target) {
// 			return {start, i};
// 		}

// 	}
// 	return {-1, -1};
// }


int main() {
	std::vector <int> vec = {-1, -2, -3, -4, -4, 8, 8, 8, 8};
	std::pair<int, int> res = sum_subarray_negative(vec, -8);
	std::cout << res.first << " " << res.second;
}