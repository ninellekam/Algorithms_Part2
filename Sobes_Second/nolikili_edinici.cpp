// дан массив из нулей и единиц и надо найти максимальный подинтервал из единиц,
// который можно получить удалением 1 элемента
// типа 0011101101
// 11101100101
// тогда ответ 111011 и длина равна 5


#include <iostream>
#include <map>
#include <vector>
#include <string>

int len_subarray(std::vector <int> & vec) {
	size_t len = vec.size(), left = 0, zeroes = 0, max_len = 0;

	for(int right = 0; right < len; ++right) {
		if (vec[right] == 0)
			++zeroes;

		while (zeroes > 1) {
			if (vec[left] == 0)
				--zeroes;
			++left;
		}

		if (vec[left] == 1)
			if (right - left > max_len)
				max_len = right - left;
	}
	return max_len;
}

int main() {
	std::vector <int> vec = {0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1 , 1 , 1 , 1, 1, 0, 1};
	std::cout << len_subarray(vec);
}
