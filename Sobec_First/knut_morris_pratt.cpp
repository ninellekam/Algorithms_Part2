#include <iostream>
#include <vector>

std::vector<int> prefix_function(const  std::string& s) {
	std::vector<int> pi(s.length(), 0);

	for (int i = 1; i < s.length(); i++) {
		int j = pi[i - 1];  //текущая длина префикса, который мы хотим продолжить
							//гарантируется, что s[0..j-1] = s[i-j..i-1].

		while (j > 0 && s[i] != s[j]) {     //пока мы не можем продолжить текущий префикс
			j = pi[j - 1];  //уменьшаем его длину до следующей возможной
		}

		//Теперь j - максимальная длина префикса, который мы можем продолжить,
		//или 0, если такового не существует.

		if (s[i] == s[j])
			pi[i] = j + 1;
		else //такое может произойти только при j = 0
			pi[i] = j;
	}

	return pi;
}

int main() {
	std::string s = "AbdbsjbxJjjscnd";
	std::string t = "Jjjsc";
	std::vector<int> pi = prefix_function(t + '#' + s);

	int t_len = t.length();

	for (int i = 0; i < s.length(); i++) {
		if (pi[t_len + 1 + i] == t_len) {
			std::cout << "s[" << i - t_len + 1 << ".." << i << "] = t" << std::endl;
		}
	}
}