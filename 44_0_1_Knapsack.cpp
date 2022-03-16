// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxValue(int weight, vector<int>& values, vector<int>& weights) {
		vector<int> dp(weight + 1);
		int n = values.size();
		
		for (int i = 0; i < n; ++i) {
			for (int wt = weight; wt > 0; --wt) {
				if (weights[i] <= wt) {
					dp[wt] = max(dp[wt], dp[wt - weights[i]] + values[i]);
				}
			}
		}

		return dp[weight];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> values(n);
		for (int& x : values) cin >> x;
		vector<int> weights(n);
		for (int& x : weights) cin >> x;
		int weight;
		cin >> weight;

		Solution solution;
		cout << solution.maxValue(weight, values, weights) << endl;
	}

	return 0;
}