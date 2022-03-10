#include<bits/stdc++.h>
using namespace std;

class Solution {
	void computeLPS(vector<int>& lps, string s) {
		int len = 0;
		int i = 1;
		int n = s.size();

		while (i < n) {
			if (s[i] == s[len]) {
				++len;
				lps[i] = len;
				++i;
				continue;
			}
			if (len == 0) ++i;
			else len = lps[len - 1];
		}
	}

public:
	int firstIndexMatch(string text, string pattern) {
		int m = text.size();
		int n = pattern.size();
		int i = 0;
		int j = 0;
		vector<int> lps(n);

		computeLPS(lps, pattern);

		while (i < m) {
			if (text[i] == pattern[j]) {
				++i;
				++j;
				if (j == n) return i - j;
				continue;
			}
			if (j == 0) ++i;
			else j = lps[j - 1];
		}

		return -1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string text, pattern;
		cin >> text >> pattern;

		Solution solution;
		cout << solution.firstIndexMatch(text, pattern) << endl;
	}

	return 0;
}