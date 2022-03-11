// https://leetcode.com/problems/balanced-binary-tree/

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

	int findHeight(TreeNode* root) {
		if (root == NULL) return 0;

		int leftHeight = findHeight(root->left);
		int rightHeight = findHeight(root->right);

		if (abs(leftHeight - rightHeight) > 1) {
			ans = false;
		}

		return 1 + max(leftHeight, rightHeight);
	}

public:
	bool isBalanced(TreeNode* root) {
		ans = true;

		findHeight(root);

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