// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<int> ans;
		queue<TreeNode*> q;

		if (root == NULL) return ans;

		q.push(root);

		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				TreeNode* currentNode = q.front();
				q.pop();
				ans.push_back(currentNode->val);
				if (currentNode->left != NULL) q.push(currentNode->left);
				if (currentNode->right != NULL) q.push(currentNode->right);
			}
		}
	    
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