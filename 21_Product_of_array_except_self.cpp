// https://leetcode.com/problems/product-of-array-except-self/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		int rightProduct = 1;
		vector<int> ans(n, 1);

		for (int i = 1; i < n; ++i) {
			ans[i] = ans[i - 1] * nums[i - 1];
		}

		for (int i = n - 1; i >= 0; --i) {
			ans[i] = ans[i] * rightProduct;
			rightProduct *= nums[i];
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
		vector<int> ans = solution.productExceptSelf(nums);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}