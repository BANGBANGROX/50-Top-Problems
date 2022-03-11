// https://leetcode.com/problems/validate-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
};

class Solution {
	bool ans;

	void isValidBSTUtil(TreeNode* root, long minValue, long maxValue) {
		if (root == NULL) return;

		isValidBSTUtil(root->left, minValue, root->val);

		if (root->val <= minValue || root->val >= maxValue) {
			ans = false;
			return;
		}

		isValidBSTUtil(root->right, root->val, maxValue);
	}
public:
	bool isValidBST(TreeNode* root) {
		ans = true;

		isValidBSTUtil(root, LONG_MIN, LONG_MAX);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}