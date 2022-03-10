// https://leetcode.com/problems/palindrome-linked-list/

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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		ListNode* previousNode = NULL;
		ListNode* currentNode = head;

		while (currentNode != NULL) {
			ListNode* nextNode = currentNode->next;
			currentNode->next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}

		return previousNode;
	}

public:
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}

		slow = reverseList(slow);

		while (slow != NULL) {
			assert(head != NULL);
			if (head->val != slow->val) return false;
			slow = slow->next;
			head = head->next;
		}

		return true;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}