// https://leetcode.com/problems/two-sum/


#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> indexes;

		for (int i = 0; i < nums.size(); ++i) {
			int a = nums[i];
			int b = target - nums[i];
			if (indexes.find(b) != indexes.end()) return { i,indexes[b] };
			indexes[a] = i;
		}

		return {};
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, target;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;
		cin >> target;

		Solution solution;
		vector<int> ans = solution.twoSum(nums, target);
		cout << ans[0] << "  " << ans[1] << endl;
	}

	return 0;
}