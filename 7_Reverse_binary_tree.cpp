// https://leetcode.com/problems/invert-binary-tree/

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
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return root;

		invertTree(root->left);
		invertTree(root->right);

		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		return root;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}