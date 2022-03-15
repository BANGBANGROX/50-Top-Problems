// https://leetcode.com/problems/remove-k-digits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<char> st;
		string ans("");
		int n = num.size();

		for (int i = 0; i < n; ++i) {
			while (!st.empty() && st.top() > num[i] && k >= 0) {
				st.pop();
				--k;
			}
			st.push(num[i]);
			if (st.size() == 1 && st.top() == '0') st.pop();
		}

		while (!st.empty() && k > 0) {
			st.pop();
			--k;
		}

		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}

		if (ans.empty()) return "0";

		reverse(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string num;
		cin >> num;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.removeKdigits(num, k) << endl;
	}

	return 0;
}