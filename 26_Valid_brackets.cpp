// https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		int n = s.size();
		stack<char> st;

		for (int i = 0; i < n; ++i) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
			else {
				char openingBracket = '(';
				if (s[i] == '}') openingBracket = '{';
				else if (s[i] == ']') openingBracket = '[';
				if (st.empty() || st.top() != openingBracket) return false;
				st.pop();
			}
		}

		return st.empty();
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		if (solution.isValid(s)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}