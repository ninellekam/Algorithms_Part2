#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


std::vector< std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
	std::vector< std::vector<std::string> > v;
	std::unordered_map <std::vector<int>, std::vector<std::string>> mp;

	for(auto it : strs) {
		std::vector<int> temp(26);

		for(size_t i = 0; i < it.size(); ++i)
			temp[it[i]-'a']++;

		mp[temp].push_back(it);
	}

	for (auto it : mp)
		v.push_back(it.second);

	return v;
}