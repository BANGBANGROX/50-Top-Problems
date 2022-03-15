// https://leetcode.com/problems/permutations-ii/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
	void reverseArray(vector<int>& nums, int l, int r) {
		while (l < r) {
			swap(nums[l], nums[r]);
			++l;
			--r;
		}
	}

	bool nextPermutation(vector<int>& nums) {
		int n = nums.size();

		if (n == 1) return false;

		int last = n - 2;

		while (last >= 0 && nums[last] >= nums[last + 1]) --last;

		if (last < 0) return false;

		int nextGreater = n - 1;

		for (int i = n - 1; i >= 0; --i) {
			if (nums[last] < nums[i]) {
				nextGreater = i;
				break;
			}
		}

		swap(nums[last], nums[nextGreater]);

		reverseArray(nums, last + 1, n - 1);

		return true;
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		unordered_set<vector<int>> st;

		sort(nums.begin(), nums.end());

		do {
			st.insert(nums);
		} while (nextPermutation(nums));

		ans = vector<vector<int>>(st.begin(), st.end());

		return ans;
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
		vector<vector<int>> ans = solution.permuteUnique(nums);
		for (const vector<int>& x : ans) {
			for (const int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}