// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
	int ans;

	int maxPathSumUtil(TreeNode* root) {
		if (root == NULL) return 0;

		int leftSum = maxPathSumUtil(root->left);
		int rightSum = maxPathSumUtil(root->right);

		ans = max(ans, max(leftSum + rightSum + root->val, max(max(leftSum, rightSum) + 
			root->val, root->val)));

		return max(max(leftSum, rightSum) + root->val, root->val);
	}

public:
	int maxPathSum(TreeNode* root) {
		ans = INT_MIN;

		maxPathSumUtil(root);

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