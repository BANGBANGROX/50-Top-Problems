// https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		int n = intervals.size();

		sort(intervals.begin(), intervals.end());

		ans.push_back(intervals[0]);

		for (int i = 1; i < n; ++i) {
			vector<int> previousInterval = ans.back();
			int prevL = previousInterval[0];
			int prevR = previousInterval[1];
			int currL = intervals[i][0];
			int currR = intervals[i][1];
			if (currL <= prevR) {
				ans.pop_back();
				ans.push_back({ prevL,max(currR,prevR) });
			}
			else ans.push_back(intervals[i]);
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
		vector<vector<int>> intervals(n, vector<int>(2));
		for (vector<int>& interval : intervals) {
			cin >> interval[0] >> interval[1];
		}

		Solution solution;
		vector<vector<int>> ans = solution.merge(intervals);
		for (const vector<int>& x : ans) {
			cout << x[0] << " " << x[1] << endl;
		}
	}

	return 0;
}