#include<bits/stdc++.h>
using namespace std;

class Solution {
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int val) {
			this->val = val;
			left = right = NULL;
		}
	};

	void inorderTraversal(TreeNode* root, vector<int>& inorder) {
		if (root == NULL) return;

		inorderTraversal(root->left, inorder);

		inorder.push_back(root->val);

		inorderTraversal(root->right, inorder);
	}

	void preorderTraversal(TreeNode* root, vector<int>& preorder) {
		if (root == NULL) return;

		preorder.push_back(root->val);

		preorderTraversal(root->left, preorder);

		preorderTraversal(root->right, preorder);
	}

	void postorderTraversal(TreeNode* root, vector<int> postorder) {
		if (root == NULL) return;

		postorderTraversal(root->left, postorder);

		postorderTraversal(root->right, postorder);

		postorder.push_back(root->val);
	}

public:
	vector<vector<int>> treeDepthFirstSearch(TreeNode* root) {
		vector<vector<int>> ans(3);
		
		inorderTraversal(root, ans[0]);

		preorderTraversal(root, ans[1]);

		postorderTraversal(root, ans[2]);

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