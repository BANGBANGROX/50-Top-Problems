// https://leetcode.com/discuss/interview-question/1273766/longest-common-substring

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestCommonSubstring(string s1, string s2) {
		int m = s1.size();
		int n = s2.size();
		int maxLen = 0;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = 0;
				maxLen = max(maxLen, dp[i][j]);
			}
		}

		return maxLen;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;

		Solution solution;
		cout << solution.longestCommonSubstring(s1, s2) << endl;
	}

	return 0;
}