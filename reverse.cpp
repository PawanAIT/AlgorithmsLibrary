#include<bits/stdc++.h>
using namespace std;
typedef  long long LL;
struct node
{
	int data;
	node *next;
};
node *GetMemory(int data)
{
	node *temp =((node*)malloc(sizeof node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void insert(node **root,int data)
{
	node *temp = *root;
	*root = GetMemory(data);
	(*root)->next = temp;
}

void reverse(node **root)
{
	node *cur = *root, *prev = NULL, *next = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*root = prev;
}
void print(node *root)
{
	while (root != NULL)
	{
		cout << root->data << " ";
		root = root->next;
	}
}
int main()
{
	node *root = NULL;
	insert(&root, 5);
	/*insert(&root, 7);
	insert(&root, 6);
	insert(&root, 9);*/
	print(root);
	reverse(&root);
	cout << endl;
	print(root);

}