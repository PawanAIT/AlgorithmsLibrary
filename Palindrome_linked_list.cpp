#include <bits/stdc++.h>
using namespace std;
struct node{
  char data;
  node *next;
};
node *get(char ch){
  node *Temp = new node();
  Temp -> data = ch;
  Temp -> next = NULL;
  return Temp;
}
node *insert(node *root , char ch){
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

node * reverse(node *root){
  node *prev = NULL , *cur = root , *next = NULL;
  while(cur != NULL){
    next = cur -> next;
    cur -> next = prev;
    prev = cur;
    cur = next;
  }
  root = prev;
  return root;
}

bool check(node *root){
  node *slow = root  , *fast = root;
  node *prev = NULL;

  if(root == NULL)return false; // No node;
  if(root -> next == NULL )return true; // single node;

  while(fast != NULL && fast->next != NULL){
    fast = fast -> next -> next;
    prev = slow;
    slow = slow -> next;
  }
    node *head2 = NULL;
    if(fast != NULL){ // odd
          head2 = slow -> next;
          slow -> next = NULL; 
    }
    else 
      head2 = prev -> next;

    prev -> next = NULL;
    head2 = reverse(head2);
   
    node *Slow = root;
    node *Fast = head2;
    bool ok = true;
    while(Fast != NULL && Slow != NULL){
      if(Fast -> data != Slow -> data){
        ok = false;
        break;
      }
        Fast = Fast -> next ;
        Slow = Slow -> next;
     }
    
    head2 = reverse(head2);
  
    if(fast != NULL){
          slow -> next = head2;
          prev -> next = slow;
    }
    else
        prev -> next = head2;
     return ok;
}

int main(){
  char arr[100];
  cin >> arr;
  int i = 0;
  node *root = NULL;
  while(arr[i]){
    root = insert(root , arr[i++]);
  }
  puts(check(root) ? "Palindrom" : "NOT Palindrom");
}
