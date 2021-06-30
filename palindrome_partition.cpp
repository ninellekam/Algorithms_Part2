
// Given a string s, partition s such that every substring of the partition is
// a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.



// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	std::vector<std::vector<std::string> > ans;

	void func (std::string s) {
		std::vector<std::string> res;
		partition(s, 0, res);
	}

	 bool isPalindrome(string s, int start, int end) {
		while(start <= end) {
			if(s[start++] != s[end--])
				return false;
		}
		return true;
	}

	void partition(std::string s, int j, std::vector<std::string> &res) {
		if (j == s.size()) {
			ans.push_back(res);
			return ;
		}

		for (int i = j; i < s.size(); ++i) {
			if (isPalindrome(s, j, i)) {
				res.push_back(s.substr(j, i - j + 1));
				partition(s, i + 1, res);
				res.pop_back();
			}
		}
	}
	void print() {
		for (auto it : ans)
			for (auto in : it)
				std::cout << in << " ";
			std::cout << "\n";
	}
};

int main() {
	Solution str;
	std::string s = "aab";
	str.func(s);
	str.print();
}