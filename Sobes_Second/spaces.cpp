#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>

// Заменить последовательности пробелов в строке
// на одиночные пробелы. O(n) по времени, O(1) по памяти.
// Пример:
// normalize("some          string ")
// "some string "


using namespace std;

std::string normalize(std::string str) {
	const char *s = str.c_str();
	size_t write_pos = 0;

	while (*s) {
		if (*s == ' ') {
			str[write_pos++] = *s;
			while (*s == ' ')
				++s;
		}
		else {
			str[write_pos++] = *s;
			++s;
		}
	}

	str.erase(str.begin() + write_pos, str.end());
	return str;
}

int main() {
	std::string str = "some     string    nina ok          okok";
	std::cout << normalize(str);
}