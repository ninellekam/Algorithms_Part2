#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unistd.h>

void find_max_subarray(std::vector <int> &vec) {
	int max = 0, len = vec.size();
	bool fl = false;
	int start = 0, end = 0, start_tmp = 0, end_tmp = 0;

	for(size_t i = 0; i < len; ++i) {
		while (vec[i] == vec[i + 1]) {
			if (fl == false) {
				start = i;
				end = i;
			}
			++i;
			++end;
			fl = true;

			if (i + 1 >= len)
				break;
		}
		fl = false;

		if (end - start > max) {
			max = end - start ;
			start_tmp = start;
			end_tmp = end;
		}
	}

	for (int i = start_tmp ; i <= end_tmp; ++i)
		std::cout << vec[i] << " ";
}

int main() {
	std::vector <int> vec = {0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
	find_max_subarray(vec);
}