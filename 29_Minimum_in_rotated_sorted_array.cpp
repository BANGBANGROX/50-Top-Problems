// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;

		if (n == 1) return nums[0];

		if (nums[0] < nums[n - 1]) return nums[0];

		while (l < r) {
			int mid = (l + ((r - l) >> 1));
			if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
			if (nums[mid] < nums[mid - 1]) return nums[mid];
			if (nums[mid] > nums[r]) l = mid + 1;
			else r = mid - 1;
		}

		return nums[l];
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
		cout << solution.findMin(nums) << endl;
	}

	return 0;
}