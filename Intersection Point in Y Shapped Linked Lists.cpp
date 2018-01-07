int intersectPoint(Node* head1, Node* head2)
{
    Node *x = head1 , *y = head2;
    int n = 0 , m = 0;
    while(x -> next){
        x = x -> next;
        n++;
    }
    while(y -> next){
        y = y -> next;
        m++;
    }
    if(x != y)
        return -1 ;
    int k = 0;
    if (n > m){
        k = n - m;
        x = head1;
        y = head2;
    }else{
         k = m - n;
         x = head2;
         y = head1;
    }
    int i = 0;
    while(i < k){
        x = x -> next;
        i++;
    }
        
    while(x && y){
        if(x == y)
            return x -> data;
        x = x -> next;
        y = y -> next;
    }
}
