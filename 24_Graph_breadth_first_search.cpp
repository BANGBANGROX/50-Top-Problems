#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> bfs(int node, vector<vector<int>>& graph) {
		int n = graph.size();
		vector<bool> visited(n);
		vector<int> ans;
		queue<int> q;

		q.push(node);

		while (!q.empty()) {
			int currentNode = q.front();
			q.pop();
			visited[currentNode] = true;
			ans.push_back(currentNode);
			for (int child : graph[currentNode]) {
				if (!visited[child]) {
					visited[child] = true;
					q.push(child);
				}
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n, node;
		cin >> m >> n;
		vector<vector<int>> graph(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		cin >> node;

		Solution solution;
		vector<int> ans = solution.bfs(node, graph);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}