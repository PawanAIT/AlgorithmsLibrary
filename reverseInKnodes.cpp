#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node* next;
};

node *reversed(node *head)
{
	node *next, *prev = NULL, *Curr = head;
	while (Curr != NULL)
	{
		next = Curr->next;
		Curr->next = prev;
		prev = Curr;
		Curr = next;
	}
	head = prev;
	return head;
}
/* Reverses the linked list in groups of size k and returns the
pointer to the new head node. */
struct node *reverse(struct node *head, int k)
{
	if (head == NULL)return NULL;
		int i = 0;
		node *temp = head;
		while (temp->next != NULL && i < k - 1)
		{
			temp = temp->next;
			i++;
		}
		node *Next = temp->next;
		temp->next = NULL;
		node *First = reversed(head);
		head->next = reverse(Next,k);
		return First;
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
void printList(struct node *node)
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
	head = reverse(head,2);

	printf("\nReversed Linked list \n");
	printList(head);

	return(0);
}