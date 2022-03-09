// https://leetcode.com/problems/find-peak-element/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		int l = 0;
		int r = n - 1;

		if (n == 1) return 0;

		while (l < r) {
			int mid = (l + ((r - l) >> 1));
			if (nums[mid] < nums[mid + 1]) l = mid + 1;
			else r = mid;
		}

		return l;
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
		cout << solution.findPeakElement(nums) << endl;
	}

	return 0;
}