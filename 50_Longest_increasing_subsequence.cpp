// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> dp;
		int n = nums.size();

		dp.push_back(nums[0]);

		for (int i = 1; i < n; ++i) {
			if (nums[i] > dp.back()) dp.push_back(nums[i]);
			int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
			dp[idx] = nums[i];
		}

		return (int)dp.size();
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		Solution solution;
		cout << solution.lengthOfLIS(nums) << endl;
	}

	return 0;
}