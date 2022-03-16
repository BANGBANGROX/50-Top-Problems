// https://leetcode.com/problems/shortest-palindrome/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> generateLPS(string s) {
		int n = s.size();
		int i = 1;
		int len = 0;
		vector<int> lps(n);

		while (i < n) {
			if (s[i] == s[len]) {
				++len;
				lps[i] = len;
				++i;
			}
			else {
				if (len == 0) ++i;
				else len = lps[len - 1];
			}
		}

		return lps;
	}

public:
	string shortestPalindrome(string s) {
		string reversedS = s;

		reverse(reversedS.begin(), reversedS.end());

		vector<int> lps = generateLPS(s + "#" + reversedS);

		int mirrorLength = lps.back();
		string ans = s.substr(mirrorLength);

		reverse(ans.begin(), ans.end());

		return ans + s;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.shortestPalindrome(s) << endl;
	}

	return 0;
}