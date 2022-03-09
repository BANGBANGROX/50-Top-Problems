// https://leetcode.com/problems/reverse-linked-list/submissions/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		next = NULL;
	}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* res = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;

		return res;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}