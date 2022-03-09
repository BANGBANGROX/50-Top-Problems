// https://leetcode.com/problems/find-the-duplicate-number/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int tortoise = nums[0];
		int hare = nums[nums[0]];

		while (tortoise != hare) {
			tortoise = nums[tortoise];
			hare = nums[nums[hare]];
		}

		tortoise = 0;

		while (tortoise != hare) {
			tortoise = nums[tortoise];
			hare = nums[hare];
		}

		return tortoise;
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
		cout << solution.findDuplicate(nums) << endl;
	}

	return 0;
}