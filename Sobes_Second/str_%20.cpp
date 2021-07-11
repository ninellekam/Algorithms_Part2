#include "stdc.h"


std::string		procent20(std::string & str) {
	size_t len = str.size(), num_of_spaces = 0;
	size_t i = len - 1;

	for (int i = 0; i < len; ++i) {
		if (str[i] == ' ')
			++num_of_spaces;
	}

	str.resize(num_of_spaces * 2 + len);
	size_t write_pos = num_of_spaces * 2 + len - 1;

	while (i > 0) {
		if (str[i] == ' ') {
			str[write_pos--] = '0';
			str[write_pos--] = '2';
			str[write_pos--] = '%';
		}
		else
			str[write_pos--] = str[i];
		--i;
	}
	return str;
}

int main() {
	std::string str = "aaaa bbb    ccc";
	std::cout << procent20(str);
}