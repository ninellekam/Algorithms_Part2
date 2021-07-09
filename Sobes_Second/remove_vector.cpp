// Даны 2 вектора отсортированных,
// нужно из первого удалить элементы, которые есть во втором.
// Не создавать дополнительных векторов #include <iostream>

#include <map>
#include <vector>
#include <string>
#include <iostream>

std::vector<int> remove_vector(std::vector<int> &a, std::vector<int> &b) {
	size_t i = 0, j = 0, write_pos = 0, len_a = a.size(), len_b = b.size();

	while (i < len_a && j < len_b) {
		if (a[i] == b[j]) {
			++i;
			++j;
			// std::cout << j;
		}
		else if (a[i] > b[j]) {
			a[write_pos++] = a[i];
			++j;
		}
		else {
			a[write_pos++] = a[i];
			++i;
		}
	}
	// std::cout << write_pos;
	while (i < len_a) {
		a[write_pos++] = a[i];
		std::cout << write_pos;
		++i;
	}

	a.erase(a.begin() + write_pos, a.end());

	for (auto it : a)
		std::cout << it;
	return a;
}

int main() {
	std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
	std::vector<int> b = {1, 2, 3, 6, 8}; // 4 5 7
	remove_vector(a, b);
}