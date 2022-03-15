// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || p == root || q == root) return root;

		TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

		if (leftLCA != NULL && rightLCA != NULL) return root;

		return leftLCA != NULL ? leftLCA : rightLCA;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}