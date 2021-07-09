#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>


void remove_smiles(std::string& str) {
	int write_pos = 0;
	const char* s = str.c_str();

	while (*s) {
		if (*s == ':' && *(s + 1) == '-' && (*(s + 2) == ')' || *(s + 2) == '(')) {
			char bracket = *(s + 2);
			s += 3;
			while (*s == bracket)
				++s;
		}
		else {
			str[write_pos++] = *s;
			++s;
		}
	}
	str.erase(str.begin() + write_pos, str.end());
}