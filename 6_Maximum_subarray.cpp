// https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = INT_MIN;
		int currentSum = 0;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			currentSum = max(nums[i], currentSum + nums[i]);
			maxSum = max(maxSum, currentSum);
		}

		return maxSum;
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
		cout << solution.maxSubArray(nums) << endl;
	}

	return 0;
}