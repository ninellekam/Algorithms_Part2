// Given an array of integers nums sorted in ascending order, find the starting and ending position
// of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		int mid = 0;
		vector<int> res;

		while (left <= right) {
			mid = (left + right) / 2;

			if (nums[mid] < target) {
				left = mid + 1;
			}
			if (nums[mid] > target) {
				right = mid - 1;
			}
			if (nums[mid] == target) {
				int tmp = mid;
				while (tmp - 1 >= 0 && nums[tmp - 1] == target) {
					--tmp;
				}
				res.push_back(tmp);
				while (mid + 1 < nums.size() && nums[mid + 1] == target) {
					++mid;
				}
				res.push_back(mid);
				return res;
			}
		}
		if (res.empty()) {
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		return res;
}

int main() {
	std::vector <int> vec = {1, 7, 7, 6, 6, 6, 6, 6, 10, 8};
	std::vector <int> res = searchRange(vec, 0);
	for (auto it : res)
		std::cout << it << " ";
}