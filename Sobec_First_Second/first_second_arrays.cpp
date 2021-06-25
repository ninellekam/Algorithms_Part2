#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>

// Даны ОТСОРТИРОВАННЫХ 2 целочисленных массива. Нужно найти все элементы, которые есть в 1-ом массиве,
// но не встречаются во 2-ом. И если элемент повторяется например 5 раз в первом
// и 4 раза во втором, то должен быть выведен этот элемент(т.к 5-го повторение во втором массиве нет)
// Пример:
// 5 5 5 5 6 7 8 9 10 11
// 2 2 2 5 5 5 6 7 9 10
// Вывод: 5, 8, 11

std::vector <int> Arrays(std::vector <int> &a, std::vector <int> &b) {
	size_t i = 0, j = 0;
	size_t len1 = a.size(), len2 = b.size();
	std::vector <int> vec_return;

	while (i < len1 && j < len2) {
		if (a[i] < b[j]) {
			vec_return.push_back(a[i]);
			++i;
		}
		if (a[i] > b[j])
			++j;
		if (a[i] == b[j]) {
			++i;
			++j;
		}
	}
	while (i < len1) {
		vec_return.push_back(a[i]);
		++i;
	}

	return vec_return;
}

int main() {
	std::vector <int> a = {5, 5, 5, 6, 7, 8, 8, 9, 11};
	std::vector <int> b = {2, 2, 5, 5, 6, 7, 8, 9, 10};

	std::vector <int> ret = Arrays(a, b);
	for (auto it : ret)
		std::cout << it << "\n";
}