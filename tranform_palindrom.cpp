#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unistd.h>
#include <string>

using namespace std;

int dp[2000][2000];
// std::memset(dp, -1, sizeof dp);

// Function defenation
int transformation(string s1, string s2,
				   int i, int j) {

	// Base cases
	if (i >= (s1.size()) || j >= (s2.size()))
		return 0;

	// Checking the ndesired condition
	if (s1[i] == s2[j]) {
		// If yes increment the cunt
		dp[i][j] = 1 + transformation(s1, s2, i + 1,
											  j + 1);
	}

	// If no
	if (dp[i][j] != -1) {
		// Return the value form the table
		return dp[i][j];
	}
	// Else store the max tranforamtion
	// from the subsequence
	else
		dp[i][j] = max(transformation(s1, s2, i, j + i),
					   transformation(s1, s2, i + 1, j));

	// Return the dp [-1][-1]
	return dp[s1.size() - 1][s2.size() - 1];
}