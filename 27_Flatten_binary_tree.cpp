// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
	void flatten(TreeNode* root) {
		if (root == NULL) return;

		flatten(root->left);
		flatten(root->right);

		TreeNode* rightSubtree = root->right;
		TreeNode* leftRightmostNode = root->left;

		root->right = leftRightmostNode;
		root->left = NULL;

		if (leftRightmostNode == NULL) {
			root->right = rightSubtree;
			return;
		}

		while (leftRightmostNode->right != NULL) {
			leftRightmostNode = leftRightmostNode->right;
		}

		leftRightmostNode->right = rightSubtree;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}