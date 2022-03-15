#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findSubsets(vector<int>& nums, int k) {
		vector<int> dp(k + 1);
		int n = nums.size();

		dp[0] = 1;

		for (int i = 0; i < n; ++i) {
			for (int sum = k; sum > 0; --sum) {
				if (nums[i] > sum) continue;
				dp[sum] += dp[sum - nums[i]];
			}
		}

		return dp[k];
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
		int k;
		cin >> k;

		Solution solution;
		cout << solution.findSubsets(nums, k) << endl;
	}

	return 0;
}