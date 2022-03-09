#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	char firstRepeatingCharacter(string s) {
		unordered_map<char, bool> visited;

		for (char& ch : s) {
			if (visited.find(ch) != visited.end()) return ch;
			visited[ch] = true;
		}

		return NULL;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.firstRepeatingCharacter(s) << endl;
	}

	return 0;
}