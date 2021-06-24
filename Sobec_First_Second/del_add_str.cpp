// Можно ли из одной строки получить
// другую заменой, удалением, добавлением 1 символа?

#include <iostream>

bool str_id_possible(std::string str1, std::string str2) {
	size_t len1 = str1.size(), len2 = str2.size();
	size_t i = -1, j = -1, count = 0;

	int delta = len1 - len2;

	if (delta < -1 || delta > 1)
		return false;

	while (++i != len1 && ++j != len2) {
		if (str1[i] != str2[j])
			++count;
		if (count > 1)
			return false;
	}

	return true;
}

int main () {
	bool ok = str_id_possible("OOOLLLLPPPJJJhhhnina", "OOOLLLLPJJJhhhnina");
	if (ok == true)
		std::cout << "YES" << "\n";
	else
		std::cout << "FALSE" << "\n";
}