#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;


int lenmax(std::string s) {
if(s.length()==0)
		return 0;
	if(s.length()==1)
		return 1;
	int len=0,maxlen=-1,i,f=0;
	unordered_map<char,int>m;
	for(i = 0; i < s.length(); i++) {
		auto it = m.find(s[i]);
		if(it != m.end()) {
			len=i-m[s[i]];
			m[s[i]]=i;
			f = 1;
		}
		else
			m.insert({s[i],i});

		if(len > maxlen)
			maxlen=len;
	}
	
	if(f==0)
		return s.length();
	return maxlen;
}