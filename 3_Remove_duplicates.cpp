#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> removeDuplicates(vector<int>& nums) {
		unordered_map<int, bool> visited;
		vector<int> ans;

		for (int& num : nums) {
			if (visited.find(num) != visited.end()) continue;
			visited[num] = true;
			ans.push_back(num);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		Solution solution;
		vector<int> ans = solution.removeDuplicates(nums);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}