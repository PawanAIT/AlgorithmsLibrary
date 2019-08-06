#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
struct node
{
	int data;
	struct node* next;
};

node* reverse(node* root) {
	node* prev = NULL;
	node* cur = root;
	node* next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return root = prev;
}

node* reverseInK(node* head, int K) {
	if (head == NULL)
		return head;
	node* curr = head;

	for (int i = 0; i < K - 1; i++) {
		if (curr->next != NULL)
			curr = curr->next;
		else
			break;
	}

	node* Next = curr->next;
	curr->next = NULL;
	node* newHead = reverse(head);
	head->next = reverseInK(Next, K);
	return newHead;
}


/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Drier program to test above function*/
int main(void)
{
	/* Start with the empty list */
	struct node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("\nGiven linked list \n");
	printList(head);
	head = reverseInK(head, 4);

	printf("\nReversed Linked list \n");
	printList(head);

	return(0);
}