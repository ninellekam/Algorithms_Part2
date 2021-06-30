#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

// vector<int> twoSum(vector<int>& nums, int target) {
// 	map<int,int> tab;
// 	vector<int> res;

// 		for(int i = 0; i < nums.size(); ++i) {
// 			if (tab.find( target - nums[i]) != tab.end()) {
// 				res.push_back(tab.find(target - nums[i])->second);
// 				res.push_back(i);
// 				return res;
// 			}
// 			else
// 				tab.insert({nums[i],i});
// 		}
// 	return res;
// }

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        int x;
       for(int i = 0;i<nums.size();i++){

          x = target - nums[i];
          if(hash.count(x)>0)
		  	return {i,hash[x]} ;

          hash[nums[i]] = i;
        }
        return {};
}