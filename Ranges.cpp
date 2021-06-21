// есть массив
// 10, 20, 1, 100, 2, 3, 4, 99
// нужно замутить строку, причем такую
// "1-4, 10, 20, 99-100»
// Ну то есть зафигачить интервалы и запихнуть все в строку через запятые

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>


std::string RangesString(std::vector <int> &vec) {
	std::sort(vec.begin(), vec.end());

	size_t len = vec.size(), count = 0;
	std::string res_str;
	for(size_t i = 0; i < len; ++i) {
		while (vec[i+1] - vec[i] == 1) {
			++i;
			++count;
		}
		if (count >= 1) {
			res_str += std::to_string(vec[i - count]) + "-" + std::to_string(vec[i]);
		}
		else
			res_str += std::to_string(vec[i]);
		count = 0;
		if (i != len - 1)
			res_str += ",";
	}
	return res_str;
}

int main() {
	std::vector <int> vec = {1, 2, 3, 4,7, 9, 10, 18, 19, 20, 100};
	std::cout << RangesString(vec);
}