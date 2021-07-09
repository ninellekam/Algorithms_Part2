// Дан семпл и текст, найти в тексте первую анаграмму семпла

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>
#include <unordered_map>

std::string sample_and_text(std::vector <std::string> &text, std::string sample) {
	size_t len = text.size();
	std::vector<int> stmp(26);
	std::unordered_map <std::string, int> hash;

	for (int i = 0; i < sample.size(); ++i) {
		stmp[sample[i] - 'a']++;
	}

	for (auto word : text) {
		std::vector<int> temp(26);
		for (int  i = 0; i < word.size(); ++i)
			temp[word[i] - 'a']++;

		if (temp == stmp)
			return word;
	}

	return "";
}

int main() {
	std::vector <std::string> text = {"nina", "ksskksk", "kdlkadjsj", "lkol"};
	std::cout << sample_and_text(text, "koll");
}