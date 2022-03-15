// https://leetcode.com/problems/decode-ways/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int n = s.size();

		if (s[0] == '0') return 0;

		int a = 1; // dp[i-2]
		int b = 1; // dp[i-1]

		for (int i = 2; i <= n; ++i) {
			if (s[i - 1] == '0') {
				if (s[i - 2] == '1' || s[i - 2] == '2') b = a; // dp[i] = dp[i-2]
				else {
					a = b; // dp[i] = 0;
					b = 0;
				}
				continue;
			}
			int c = b; // dp[i] = dp[i-1]
			if (s[i - 2] == '0') {
				a = b;
				continue;
			}
			int number = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
			if (number <= 26) c += a; // dp[i] += dp[i-2]
			a = b;
			b = c;
		}

		return b;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.numDecodings(s) << endl;
	}

	return 0;
}