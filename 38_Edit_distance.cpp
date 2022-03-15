// https://leetcode.com/problems/edit-distance/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		const int inf = 1e9;
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, inf));

		for (int i = 0; i <= m; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == 0 || j == 0) {
					dp[i][j] = i + j;
					continue;
				}
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
				}
			}
		}

		return dp[m][n];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}