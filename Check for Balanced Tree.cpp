bool f = true;
int ans(Node *root){
    if(root == NULL)
        return 0;
    int l = ans(root -> left);
    int r = ans(root -> right);
    if(abs(l-r) > 1)
        f = false;
    return 1 + max(l , r);
}
bool isBalanced(Node *root)
{
    f = true;
    ans(root);
    return f;
}
