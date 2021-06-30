#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> threeSum(vector<int> &nums) {

		vector<vector<int>> ans;

		int n = nums.size();

		sort(nums.begin(), nums.end());

		int low, high;

		for (int i = 0; i < n; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			low = i + 1;
			high = n - 1;

			while (low < high) {
				int sum = nums[i] + nums[low] + nums[high];
				if (sum == 0) {
					ans.push_back({nums[i], nums[low], nums[high]});
					while (low < high && nums[low] == nums[low + 1])
						low++;

					while (low < high && nums[high - 1] == nums[high])
						high--;
					low++;
					high--;
				}

				else if (sum < 0)
					low++;
				else
					high--;
			}
		}

		return ans;
}