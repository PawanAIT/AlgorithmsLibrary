#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node *get(int data)
{
    node *temp=new node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
int lol=0;
int search(char in[],int start,int end,char ch)
{
    for(int i=start;i<=end;i++)
        if(in[i]==ch)
            return i;
}
node* build(char in[],char pt[],int start,int end)
{
    if(start > end)
        return NULL;
    node *temp=get(pt[lol++]);
    if(start==end)
        return temp;
    int index= search(in,start,end,temp->data);
    temp->left=build(in,pt,start,index-1);
    temp->right=build(in,pt,index+1,end);
    return temp;
}
void disp(node *root)
{
    if(root)
    {
        disp(root->left);
        cout<<(char)root->data<<" ";
        disp(root->right);
    }
}
int main()
{
    char in[]={"DBEAFC"};
    char  pt[]={"ABDECF"};
    int start=0,end=strlen(in)-1;
    node *root=build(in,pt,start,end);
    disp(root);
    return 0;
}
