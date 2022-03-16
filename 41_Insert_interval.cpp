// https://leetcode.com/problems/insert-interval/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int n = intervals.size();
		int i = 0;
		vector<vector<int>> ans;

		while (i < n && intervals[i][1] < newInterval[0]) {
			ans.push_back(intervals[i]);
			++i;
		}

		while (i < n && intervals[i][0] <= newInterval[1]) {
			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);
			++i;
		}

		ans.push_back(newInterval);

		while (i < n) {
			ans.push_back(intervals[i]);
			++i;
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
		vector<int> newInterval(2);
		cin >> newInterval[0] >> newInterval[1];

		Solution solution;
		vector<vector<int>> ans = solution.insert(intervals, newInterval);
		for (const vector<int>& x : ans) {
			for (const int& y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}