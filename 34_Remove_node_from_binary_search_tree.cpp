// https://leetcode.com/problems/delete-node-in-a-bst/

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
	TreeNode* inorderSuccessor(TreeNode* root) {
		TreeNode* right = root->right;

		while (right->left != NULL) {
			right = right->left;
		}

		return right;
	}

public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == NULL) return root;

		if (root->val == key) {
			if (root->left == NULL) {
				TreeNode* rightSubtree = root->right;
				delete root;
				return rightSubtree;
			}
			else if (root->right == NULL) {
				TreeNode* leftSubtree = root->left;
				delete root;
				return leftSubtree;
			}
			else {
				TreeNode* successor = inorderSuccessor(root);
				root->val = successor->val;
				root->right = deleteNode(root->right, successor->val);
				return root;
			}
		}

		else if (root->val < key) {
			root->right = deleteNode(root->right, key);
		}

		else root->left = deleteNode(root->left, key);

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