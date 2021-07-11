// Дана квадратная матрица NxN, заполненная нулями и единицами таким образом,
// что в каждой строке все нули располагаются левее всех единиц (возможны строки,
// состоящие полностью из нулей или полностью из единиц). Требуется определить номер
// первой колонки, в которой есть хоть одна единица.
// (сложность O(n) должна быть !!) (вроде он сказал что здесь будет O(2n))

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>
#include <unordered_map>


int matrix(std::vector< std::vector<int> > & matrix) {
	size_t rows = matrix.size();
	int left = 0, right = rows - 1, mid = 0;
	int index_one = rows, ans = INT_MAX, j = rows - 1;

	for (int i = 0; i < rows; ++i) {
		while (matrix[i][j] != 0) {
			if (j == 0) {
				std::cout << "\nANSWER ";
				return j;
			}
			--j;
		}
	}

	ans = j + 1;
	std::cout << "\nANSWER ";
	return ans;
}

int main() {
	std::vector< std::vector<int> > mat = {{0, 0, 0, 0},
										   {0, 0, 0, 0},
										   {1, 1, 1, 1},
										   {0, 0, 1, 1}};
	std::cout << matrix(mat);
}