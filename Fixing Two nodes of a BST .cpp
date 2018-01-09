/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function
Node is as follows:
struct node
{
    int data;
    struct node *left, *right;
};
*/
node *first , *second , *Prev = NULL;
void ans(node *root){
    if(root == NULL)
        return ;
    
    ans(root -> left );
    if(Prev != NULL){
        if(Prev ->data > root -> data){
            if(first == NULL){
                first = root ;
            }
            else{
                second = root;
            }
        }
    }
    Prev = root;
    ans(root -> right);
}
struct node *correctBST( struct node* root )
{
    Prev = NULL;
    first = NULL;
    second  = NULL;
    ans(root);
    swap(first -> data , second -> data);
    return root;
}
