#include "bits/stdc++.h"
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == NULL)
			return head;

		ListNode * slow = head;
		ListNode * fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				slow = head;
				while (slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return NULL;
	}
};
int main() {
	
	return 0;
}
