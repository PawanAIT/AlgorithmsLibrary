#include <bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node *next;
};
node *get(int ch){
  node *Temp = new node();
  Temp -> data = ch;
  Temp -> next = NULL;
  return Temp;
}
node *insert(node *root , int ch){
  if(root == NULL)
    return get(ch);
  node *temp  = get(ch);
  temp -> next = root;
  return temp;
}
void print(node *root){
  while(root){
    cout << root -> data << " ";
    root = root -> next;
  }
}

void reverse(node *head , node *&ans){
	if(head == NULL)
		return ;
	if(head -> next == NULL){
		ans = head; 
		return;
	}
	reverse(head -> next , ans);
	node * p = head -> next; 
	p -> next = head;
	head ->next = NULL;
}

int main(){
 	int n ;
 	node *head = NULL;
 	node *ans = NULL;
 	while(cin >> n)
 		head = insert(head , n);
 	print(head);
 	reverse(head , ans);
 	print(ans);
}
