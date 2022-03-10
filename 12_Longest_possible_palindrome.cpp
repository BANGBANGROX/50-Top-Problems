// https://leetcode.com/problems/longest-palindrome/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		vector<int> count(128);
		int maximumLength = 0;
		int maximumOddCountLetter = -1;
		int maximumOddCount = 0;

		for (char& c : s) ++count[c];

		for (int i = 0; i < 128; ++i) {
			if ((count[i] & 1) == 0) maximumLength += count[i];
			else if (maximumOddCount < count[i]) {
				maximumOddCount = count[i];
				maximumOddCountLetter = i;
			}
		}

		if (maximumOddCountLetter == -1) return maximumLength;

		maximumLength += maximumOddCount;

		for (int i = 0; i < 128; ++i) {
			if ((count[i] & 1) > 0 && maximumOddCountLetter != i) maximumLength += (count[i] - 1);
		}

		return maximumLength;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.longestPalindrome(s) << endl;
	}

	return 0;
}