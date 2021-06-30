#include <iostream>
#include <vector>
#include <string>

int	maxest(std::string &s) {
	int max_dist = 0;
	int i = 0, len = s.size(), diff = 0;
	int indx_x = 0, indx_y = 0;

	auto it = s.find('X');
	if (it != s.std::string::npos)
		indx_x = it;

	it = s.find('Y');
	if (it != s.std::string::npos)
		indx_y = it;

	i = it;

	while (i < len) {
		if (s[i] == 'X')
			diff = abs(indx_y - i);

		if (s[i] == 'Y')
			diff = abs(indx_x - i);

		if (diff > max_dist)
				max_dist = diff;
		++i;
	}
	if (max_dist == 0)
		return max_dist;
	return max_dist - 1;
}

int main() {
	std::string s = "XOOOCCCXY";
	std::cout << maxest(s);
}