#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <deque>

std::vector<int> minSlidingWindow(std::vector <int> & arr, int k) {
		std::vector <int> result;
		std::deque <int> Q(k);

		for(int i = 0; i < k; i++) {
			while(!Q.empty() and arr[i] <= arr[Q.back()])
				Q.pop_back();
			Q.push_back(i);
		}

		int i = k;

		for(i = k; i < arr.size(); ++i) {

			result.push_back(arr[Q.front()]);

			while(!Q.empty() and Q.front() <= i - k)
				Q.pop_front();

			while(!Q.empty() and arr[i] <= arr[Q.back()]) {
				Q.pop_back();
			}

			Q.push_back(i);
		}

		result.push_back(arr[Q.front()]);
		return result;
}

int main() {
	std::vector<int> vec = {7, 5,8, 15, 67, 23, 555,  21, 100, 44};
	std::vector<int> res = minSlidingWindow(vec, 3);

	for (auto it : res)
		std::cout << it << " ";
}
