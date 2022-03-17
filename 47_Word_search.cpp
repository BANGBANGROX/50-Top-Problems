// https://leetcode.com/problems/word-search/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool dfs(vector<vector<char>>& board, string word, int idx, int x, int y, vector<vector<bool>>& visited) {
		int m = board.size();
		int n = board[0].size();
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,1,0,-1 };

		visited[x][y] = true;

		if (idx == word.size()) {
			visited[x][y] = false;
			return true;
		}

		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newX < m && newY >= 0 && newY < n
				&& !visited[newX][newY] && word[idx] == board[newX][newY]) {
				if (dfs(board, word, idx + 1, newX, newY, visited)) {
					visited[newX][newY] = false;
					return true;
				}
			}
		}

		visited[x][y] = false;

		return false;
	}

public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (word[0] == board[i][j]) {
					if (dfs(board, word, 1, i, j, visited)) return true;
				}
			}
		}

		return false;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<char>> board(m, vector<char>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> board[i][j];
			}
		}
		string word;
		cin >> word;

		Solution solution;
		if (solution.exist(board, word)) cout << "true\n";
		else cout << "false";
	}

	return 0;
}