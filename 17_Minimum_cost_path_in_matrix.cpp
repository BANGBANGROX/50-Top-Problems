// https://leetcode.com/problems/minimum-path-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (i == m - 1 && j == n - 1) continue;
				else if (i == m - 1) grid[i][j] += grid[i][j + 1];
				else if (j == n - 1) grid[i][j] += grid[i + 1][j];
				else grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
			}
		}

		return grid[0][0];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> grid(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}
		
		Solution solution;
		cout << solution.minPathSum(grid) << endl;
	}

	return 0;
}