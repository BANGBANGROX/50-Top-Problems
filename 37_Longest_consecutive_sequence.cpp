// https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		unordered_set<int> present;

		for (int num : nums) present.insert(num);

		for (int num : nums) {
			if (present.find(num - 1) != present.end()) continue;
			int count = 0;
			while (present.find(num) != present.end()) {
				++count;
				++num;
			}
			ans = max(ans, count);
		}

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
		cout << solution.longestConsecutive(nums) << endl;
	}

	return 0;
}