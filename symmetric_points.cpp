#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>


struct point {
	long long x;
	long long y;
	point(long long x = 0, long long y = 0, long long z = 0): x(x), y(y) {}

	bool operator<(const point &oth) const{
		if(x < oth.x || (x == oth.x && (y < oth.y)))
			return true;
		else
			return false;
	}

	point operator+(const point &A) {
		return point(x + A.x, y + A.y);
	}
};

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int N;
	std::cin >> N;

	std::vector<point> vec(N);
	std::set<point> S;
	point min, max;

	std::cin >> vec[0].x >> vec[0].y;

	min = max = vec[0];
	S.insert(vec[0]);

	for(int i = 1; i < N; ++i) {
		std::cin >> vec[i].x >> vec[i].y;

		S.insert(vec[i]);

		if(vec[i] < min)
			min = vec[i];

		if(max < vec[i])
			max = vec[i];
	}
	point c = max + min;

	for(int i = 0; i < N; ++i) {
		point temp(c.x - vec[i].x, c.y - vec[i].y);

		if(S.find(temp) == S.end()) {
			std::cout << "No";
			return 0;
		}
	}

	std::cout << "Yes";
	return 0;
}