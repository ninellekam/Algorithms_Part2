#include <iostream>
#include <vector>
#include <string>

int	shortest(std::string &s) {
	size_t n = s.size();
	int indx_x = 0, indx_y = 0, min_dist = INT_MAX;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'X') {
			indx_x = i;
		}
		if (s[i] == 'Y') {
			indx_y = i;
		}
		int diff = 0;
		if (indx_x != indx_y) {
			diff = abs(indx_y - indx_x);
			if (diff < min_dist)
				min_dist = diff;
		}
	}
	return min_dist - 1;
}

int main() {
	std::string s = "XXXXXXOJOJLLJYXY";
	std::cout << shortest(s);
}