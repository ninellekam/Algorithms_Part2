//  Reverse words in a string

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

std::string reverse_words(std::string &str) {
	std::stack<std::string> my_stack;
	size_t len = str.size();
	int prev = 0, index_space = 0;

	index_space = str.find(' ');
	while (index_space != std::string::npos) {
		std::string word = str.substr(0, index_space);
		str = str.substr(index_space + 1, std::string::npos);
		my_stack.push(word);
		index_space = str.find(' ');
	}

	my_stack.push(str.substr(0, std::string::npos));
	
	std::string res = "";
	while (!my_stack.empty()) {
		std::string word = my_stack.top();
		res += word + " ";
		my_stack.pop();
	}
	return res;
}

int main() {
	std::string s = "nina kamkia hi hello op";
	std::cout << reverse_words(s);
	return 0;
}