#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;
	string longestPalindrome(string s) {
		int max = 0, left = 0;
		for(int i=0; i<s.size(); ++i){
			int l=i, r=i;
			while(r+1<s.size() && s[r]==s[r+1]){
				++r;
			}
			while(l-1>=0 && r+1<s.size() && s[l-1]==s[r+1]){
				--l;
				++r;
			}
			int len = r - l + 1;
			if(len>max){
				max = len;
				left = l;
			}
		}
	return s.substr(left,max);
}