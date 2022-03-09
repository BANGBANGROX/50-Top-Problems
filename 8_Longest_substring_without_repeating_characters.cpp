// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		int l = 0;
		int maxLen = 0;
		vector<int> count(256);

		for (int r = 0; r < n; ++r) {
			++count[s[r]];
			if (count[s[r]] == 1) {
				maxLen = max(maxLen, (r - l + 1));
				continue;
			}
			while (count[s[r]] > 1) {
				--count[s[l]];
				++l;
			}
		}

		return maxLen;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.lengthOfLongestSubstring(s) << endl;
	}

	return 0;
}