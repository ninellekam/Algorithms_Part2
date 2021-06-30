// Given an integer array nums of unique elements,
// return all possible subsets (the power set).
// The solution set must not contain duplicate subsets.
// Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

#include <vector>
#include <iostream>

using namespace std;

void generateSubsets(vector<int>& nums , int ind, vector<int> &st,  vector<vector <int> > &res){
		res.push_back(st);

		for (int i = ind; i < nums.size(); ++i) {
			st.push_back(nums[i]);
			generateSubsets(nums , i+1 , st, res);
			st.erase(st.end() - 1);
		}
	}

vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > res;
		vector<int> st;

		generateSubsets(nums, 0, st, res);

		return res;
}

int main () {
	std::vector <int > vec = {1, 2, 3};
	std::vector <vector <int> > vec1 = subsets(vec);
	for (auto it : vec1) {
		for (auto in : it)
			std::cout << in << " ";
		std::cout << "\n";
	}
}