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
node *add(node *a , node *b){
  int carry = 0;
  node *c = NULL;
  while(a && b){
      int data = a->data + b -> data + carry;
      carry = data / 10;
      data = data % 10;
      c = insert(c , data);
      a = a -> next;
      b = b -> next;
  }
  while(a){
    int data = a->data + carry;
    carry = data / 10;
    data = data  % 10;
    c = insert(c , data);
    a = a -> next;
  }
  while(b){
    int data = b -> data + carry ;
    carry = data / 10;
    data = data % 10;
    c = insert(c , data);
    b = b -> next; 
  }
  if(carry){
    c = insert(c, carry);
  }
  return c;
}


int main(){
  int arr[100] = {0};
  int b[100] = {0};
  int n , m;
  cin >> n >> m;
  for(int i = 0 ;i < n ; i++){
      cin >> arr[i];
  }
  for(int i = 0 ; i < n; i++){
      cin >> b[i];
  }
  int i = 0;
  node *A = NULL;
  node *B = NULL;
  while(i < n){
    A = insert(A , arr[i++]);
  }
  for(i = 0 ; i < m ; i++)
    B = insert(B , b[i]);


  node *C = add(A , B);
 
  print(C);

}
