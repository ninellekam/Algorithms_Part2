#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void MaxSubstring(std::string str) {
	std::string str_return;
	bool fl = false;
	int max_tmp = 0;
	size_t len = str.size(), start = 0, end = 0;

	for(size_t i = 0; i < len; ++i) {
		while (str[i] == str[i + 1]) {
			if (fl == false) {
				start = i;
				end = i;
			}
			fl = true;
			++end;
			++i;
		}
		fl = false;
		if (end - start > max_tmp) {
			str_return = str.substr(start, end - start + 1);
			max_tmp = end - start;
		}
	}
	std::cout << str_return << "\n";
}

int main() {
	MaxSubstring("aaabbbba");
}