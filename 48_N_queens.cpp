// https://leetcode.com/problems/n-queens-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isNotAttacked(vector<vector<bool>>& board, int row, int col) {
		int i = row - 1;
		int jLeft = col - 1;
		int jRight = col + 1;
		int n = board.size();

		while (i >= 0) {
			if (board[i][col] || (jLeft >= 0 && board[i][jLeft])
				|| (jRight < n && board[i][jRight])) return false;
			--i;
			--jLeft;
			++jRight;
		}

		return true;
	}

	int totalNQueens(vector<vector<bool>>& board, int row) {
		int n = board.size();

		if (row == n) return 1;

		int sumWays = 0;

		for (int i = 0; i < n; ++i) {
			if (isNotAttacked(board, row, i)) {
				board[row][i] = true;
				sumWays += totalNQueens(board, row + 1);
				board[row][i] = false;
			}
		}

		return sumWays;
	}

public:
	int totalNQueens(int n) {
		vector<vector<bool>> board(n, vector<bool>(n));

		return totalNQueens(board, 0);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		Solution solution;
		cout << solution.totalNQueens(n) << endl;
	}

	return 0;
}