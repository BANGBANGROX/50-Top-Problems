// https://leetcode.com/problems/unique-paths-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		bool blockadeFound = false;

		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

		for (int i = n - 2; i >= 0; --i) {
			if (obstacleGrid[m - 1][i] == 1) {
				obstacleGrid[m - 1][i] = 0;
				blockadeFound = true;
				continue;
			}
			if (!blockadeFound) obstacleGrid[m - 1][i] = 1;
		}

		blockadeFound = false;

		for (int i = m - 1; i >= 0; --i) {
			if (obstacleGrid[i][n - 1] == 1) {
				obstacleGrid[i][n - 1] = 0;
				blockadeFound = true;
				continue;
			}
			if (!blockadeFound) obstacleGrid[i][n - 1] = 1;
		}

		for (int i = m - 2; i >= 0; --i) {
			for (int j = n - 2; j >= 0; --j) {
				if (obstacleGrid[i][j] == 1) {
					obstacleGrid[i][j] = 0;
					continue;
				}
				obstacleGrid[i][j] = min((long)obstacleGrid[i + 1][j] + obstacleGrid[i][j + 1], 
					(long)INT_MAX);
				if (obstacleGrid[i][j] == INT_MAX && i != 0 && j != 0) obstacleGrid[i][j] = 0;
			}
		}

		return obstacleGrid[0][0];
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<int>> obstacleGrid(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> obstacleGrid[i][j];
			}
		}

		Solution solution;
		cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
	}

	return 0;
}