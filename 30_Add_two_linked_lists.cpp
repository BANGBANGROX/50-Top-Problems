// https://leetcode.com/problems/add-two-numbers/

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode* resHead = new ListNode(0);
		ListNode* resTail = resHead;

		while (l1 != NULL && l2 != NULL) {
			int val = l1->val + l2->val + carry;
			resTail->next = new ListNode(val % 10);
			carry = val / 10;
			l1 = l1->next;
			l2 = l2->next;
			resTail = resTail->next;
		}

		if (l2 != NULL) l1 = l2;

		while (l1 != NULL) {
			resTail->next = new ListNode((l1->val + carry) % 10);
			carry = (l1->val + carry) / 10;
			l1 = l1->next;
			resTail = resTail->next;
		}

		if (carry > 0) resTail->next = new ListNode(carry);

		return resHead->next;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}