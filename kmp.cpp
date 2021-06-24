#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


class kmp_numeric {
private:
	int n;
	int** dfa;

public:
	kmp_numeric(string& s) {
		n = s.length();
		int c = 256;

		dfa = new int*[n];

		for (int i = 0; i < n; i++)
			dfa[i] = new int;

		int x = 0;

		for (int i = 0; i < c; i++)
			dfa[0][i] = 0;

		dfa[0][s[0]] = 1;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < c; j++)
				dfa[i][j] = dfa[x][j];

			dfa[i][s[i]] = i + 1;
			x = dfa[x][s[i]];
		}
	}

	int longest_overlap(string& query) {
		int ql = query.length();
		int state = 0;

		for (int i = 0; i < ql; i++) {
			state = dfa[state][query[i]];
		}
		return state;
	}
};

int min_appends(string& s) {
	reverse(s.begin(), s.end());

	kmp_numeric kmp = s;

	reverse(s.begin(), s.end());

	int ans = s.length() - kmp.longest_overlap(s);
	return ans;
}

int main()
{
	string s = "deep";
	// Answer : 3

	string t = "sososososos";
	// Answer : 0

	cout << min_appends(s) << endl;
	cout << min_appends(t) << endl;
}