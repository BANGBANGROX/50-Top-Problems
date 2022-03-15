#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<string> ans;

	void generateSubsequences(string& s, int i, string& current) {
		if (i == s.size()) {
			ans.push_back(current);
			return;
		}

		// Take the current letter
		current += s[i];
		generateSubsequences(s, i + 1, current);

		// Leave the current letter
		current.pop_back();
		generateSubsequences(s, i + 1, current);
	}

public:
	vector<string> printSubsequences(string s) {
		string current("");

		generateSubsequences(s, 0, current);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		vector<string> ans = solution.printSubsequences(s);
		for (string& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}