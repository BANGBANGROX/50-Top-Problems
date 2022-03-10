// https://leetcode.com/problems/sort-list/

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
	ListNode* midNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* prevNode = NULL;

		while (fast != NULL && fast->next != NULL) {
			prevNode = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		assert(prevNode != NULL);

		prevNode->next = NULL;

		return slow;
	}

	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* resHead = new ListNode(0);
		ListNode* resTail = resHead;

		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				resTail->next = l1;
				l1 = l1->next;
			}
			else {
				resTail->next = l2;
				l2 = l2->next;
			}
			resTail = resTail->next;
		}

		resTail->next = (l1 != NULL) ? l1 : l2;

		return resHead->next;
	}

public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* mid = midNode(head);

		ListNode* left = sortList(head);
		ListNode* right = sortList(mid);
		ListNode* res = merge(left, right);

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