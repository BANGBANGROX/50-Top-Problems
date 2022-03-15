#include<bits/stdc++.h>
using namespace std;

class Solution {
	void dfsUtil(int node, vector<vector<int>>& graph, vector<int>& ans, vector<bool> visited) {
		visited[node] = true;

		ans.push_back(node);

		for (int child : graph[node]) {
			if (!visited[child]) dfsUtil(child, graph, ans, visited);
		}
	 }

public:
	vector<int> dfs(int node, vector<vector<int>>& graph, int n) {
		vector<int> ans;
		vector<bool> visited(n);

		dfsUtil(node, graph, ans, visited);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n, node;
		cin >> n >> m;
		vector<vector<int>> graph(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		cin >> node;

		Solution solution;
		vector<int> ans = solution.dfs(node, graph, n);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}