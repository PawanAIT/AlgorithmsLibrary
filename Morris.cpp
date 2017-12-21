#include <bits/stdc++.h>
using namespace std;
 
struct node
{
  node * left;
  node* right;
  int data;
};
 
node* newNode(int x)
{
  node* temp=new node();
  temp->left=NULL;
  temp->right=NULL;
  temp->data=x;
  return temp;
}

int Morris(node *root){
      node *cur = root;
      while(cur != NULL){
          if(cur -> left == NULL){
            cout << cur -> data << " ";
            cur = cur -> right;
          }
          else{
              node * p = cur -> left;
              while(p -> right != NULL and p -> right != cur)
                  p = p -> right;
              if(p -> right == cur){
                p -> right = NULL;
                 cout << cur -> data << " ";
                cur = cur -> right;
              }else{
                  p -> right = cur ;
                  cur = cur -> left;
              }
          }
      }
}

void print(node *root){
    if(root == NULL)
      return ;
    print(root -> left);
    cout << root -> data <<" ";
    print(root -> right);
}
int main()
{
  struct node *root = newNode(56);
  root->left = newNode(13);
  root->right = newNode(15);
  root->left->left = newNode(5);
  root->left->right = newNode(3);
  root->left ->left -> left = newNode(3);
  root->left ->left -> right = newNode(2);
  root -> right -> right = newNode(3);
  root -> right ->left =newNode(9);
  root -> right -> right -> right = newNode(1);
  root -> right -> right -> left = newNode(2);
  Morris(root);
  printf("\n");
  print(root);
  return 0;
}
