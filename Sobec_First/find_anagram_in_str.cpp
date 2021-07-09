#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>

std::string checkInclusion(std::string s1, std::string s2) {
		std::vector<int> cnt1(26), cnt2(26);

		for(char c:s1)
			++cnt1[c -'a'];

		for(int i = 0; s2[i]; i++){
			++cnt2[s2[i]-'a'];

			if (i >= s1.size())
				--cnt2[s2[i-s1.size()]-'a'];

			if (cnt1 == cnt2) {
				return s2.std::string::substr(i - s1.size() + 1, s1.size());
			}
		}
		return "nothing";
}

int main() {
	std::string s1 = "inan", s2 = "eiddsadkadkninaooook";
	std::cout << checkInclusion(s1, s2);
}