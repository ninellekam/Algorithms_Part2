#include <iostream>
#include <map>
#include <vector>
#include <string>

std::string pack(char &lastsym, int cnt) {
	std::string ret = "";
	ret += lastsym ;
	if (cnt != 1)
		return ret + std::to_string(cnt);
	return ret;
}

std::string a1b2d4(std::string s) {
	std::string res = "";
	int  lastpos = 0;
	char lastsym = s[0];

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != lastsym) {
			res += pack(lastsym, i - lastpos);
			lastpos = i;
			lastsym = s[i];
		}
	}
	res += pack(s[s.size() - 1], s.size() - lastpos);
	return res;
}

int main() {
	std::cout << a1b2d4("VVVBB");
}