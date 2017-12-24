Node * findNext(Node *r){
        if(!r) return NULL;
        Node * s = r->nextRight;
        while(s){
            if(s->left) return s->left;
            if(s->right) return s->right;
            s=s->nextRight;
        }
        return NULL;
}
void connect(Node *p)
{
    if(!p) return;
    p->nextRight = NULL;

    while(p){

        Node *q = p;
        
        while(q){
            
            if(q->left){
                if(q->right) {q->left->nextRight = q->right;}
                else q->left->nextRight = findNext(q);
            }
            if(q->right){
                q->right->nextRight = findNext(q);
            }
            q = q->nextRight;
        }

        if(p->left) p = p->left;
        else if(p->right) p = p->right;
        else p = findNext(p); 
    }
}
