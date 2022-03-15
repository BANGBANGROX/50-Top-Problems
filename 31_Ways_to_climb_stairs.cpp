#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findWays(vector<int>& steps, int n) {
		vector<int> dp(n + 1);

		dp[0] = 1;

		for (int i = 1; i <= n; ++i) {
			for (int& step : steps) {
				if (i >= step) dp[i] += dp[i - step];
			}
		}

		return dp[n];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		vector<int> steps(m);
		for (int& x : steps) cin >> x;

		Solution solution;
		cout << solution.findWays(steps, n) << endl;
	}

	return 0;
}