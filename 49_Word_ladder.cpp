// https://leetcode.com/problems/word-ladder/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dictionary(wordList.begin(), wordList.end());
		unordered_set<string> visited;
		queue<string> q;
		int length = 1;

		if (dictionary.find(endWord) == dictionary.end()) return 0;

		q.push(beginWord);

		while (!q.empty()) {
			++length;
			int n = q.size();
			while (n--) {
				string currWord = q.front();
				q.pop();
				visited.insert(currWord);
				string nextWord = currWord;
				for (int i = 0; i < currWord.size(); ++i) {
					for (char c = 'a'; c <= 'z'; ++c) {
						if (currWord[i] == c) continue;
						nextWord[i] = c;
						if (dictionary.find(nextWord) != dictionary.end() &&
							visited.find(nextWord) == visited.end()) {
							q.push(nextWord);
							visited.insert(nextWord);
							if (nextWord.compare(endWord) == 0) return length;
						}
						nextWord[i] = currWord[i];
					}
				}
			}
		}

		return 0;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string beginWord, endWord;
		cin >> beginWord >> endWord;
		int n;
		cin >> n;
		vector<string> wordList;
		for (string& x : wordList) cin >> x;

		Solution solution;
		cout << solution.ladderLength(beginWord, endWord, wordList) << endl;
	}

	return 0;
}