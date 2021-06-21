#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class MyClass {
	std::vector <int> vec;
	std::map <int, int> Map;

	public:
		void add(int elem) {
			int index = vec.size();
			Map[elem] = index;
			vec.push_back(elem);
		}
		void remove(int elem) {
			if (Map.find(elem) == Map.end())
				return ;

			int index = Map[elem];
			Map.erase(elem);

			std::swap(vec[index], vec[vec.size() - 1]);
			vec.pop_back();

			Map[elem] = index;
		}
		int random() {
			int index_random = rand() % vec.size();
			return vec[index_random];
		}

		int find(int elem) {
			if (Map.find(elem) != Map.end()) {
				int index = Map[elem];
				return index;
			}
			else
				return -1;
		}
};

int main() {
	MyClass ds;
	ds.add(10);
	ds.add(20);
	ds.add(30);
	ds.add(40);
	std::cout << ds.find(30) << std::endl;
	ds.remove(20);
	ds.add(50);
	std::cout << ds.find(50) << std::endl;
	std::cout << ds.random() << std::endl;
}