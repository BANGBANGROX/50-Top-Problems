// https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int maxReach = nums[0];
		int steps = nums[0];

		if (n == 1) return true;

		if (nums[0] == 0) return false;

		for (int i = 1; i < n; ++i) {
			if (i == n - 1) return true;
			maxReach = max(maxReach, i + nums[i]);
			--steps;
			if (steps == 0) {
				if (i >= maxReach) return false;
				steps = maxReach - i;
			}
		}

		return true;
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
		if (solution.canJump(nums)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}