#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int vno,lower,*rcm,level;
    struct node *parent;
}node;

typedef struct qnode
{
    node *addr;
    struct qnode *next;
}qnode;

void input(int *graph,int n)
{
     for (int i = 0; i < n; ++i)
         for (int j = 0; j < n; ++j)
                scanf("%d",&graph[i*n+j]);
         
}

void enqueue(qnode **head,node *newnode)
{
    qnode *newqnode=(qnode *)malloc(sizeof(qnode));
    newqnode->addr=newnode;
    newqnode->next=NULL;
    if(*head==NULL) 
    {
        *head=newqnode; 
    }
    else
    {
        qnode *temp;
        temp=*head;
        if(newnode->lower<temp->addr->lower)
        {
            newqnode->next=temp;
            temp=newqnode;
            *head=temp;
        }
        else
        {
            while(temp->next!=NULL && temp->next->addr->lower<=newnode->lower)  
            {
                temp=temp->next;    
            }
            newqnode->next=temp->next;
            temp->next=newqnode;
        }
    }
}

void enqueuedead(qnode **head,node *newnode)
{
    qnode *newqnode=(qnode *)malloc(sizeof(qnode));
    newqnode->addr=newnode;
    newqnode->next=*head;
    *head=newqnode;
}

node *dequeue(qnode **head)
{
    node *newnode;
    newnode=(*head)->addr;
    qnode *temp;
    temp=*head;
    *head=(*head)->next;
    free(temp);
    return newnode;
}
void copy(int *out,int *in,int n)
{
    int i,j;
    for(i=0;i<n;i++)    
    {
        for(j=0;j<n;j++)
        {
            in[i*n+j]=out[i*n+j];
        }
    }
}
int rcm(int *g,int n)
{
    int min,c=0,i,j;
    
    for(i=0;i<n;i++)
    {
        min=INT_MAX;
        for(j=0;j<n;j++)
        {
            if(g[i*n+j]!=INT_MAX && g[i*n+j]<min)   
            {
                min=g[i*n+j];
            }
        }
        if(min!=INT_MAX && min!=0)
        {
            c+=min;
            for(j=0;j<n;j++)
            {
                if(g[i*n+j]!=INT_MAX)
                {
                    g[i*n+j]-=min;
                }
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        min=INT_MAX;
        for(j=0;j<n;j++)
        {
            if(g[j*n+i]!=INT_MAX && g[j*n+i]<min)   
            {
                min=g[j*n+i];
            }
        }
        if(min!=INT_MAX && min!=0)
        {
            c+=min;
            for(j=0;j<n;j++)
            {
                if(g[j*n+i]!=INT_MAX)
                {
                    g[j*n+i]-=min;
                }
            }
        }
    }
    return c;
}

int empty(qnode *head)
{
    if(head==NULL)
    {
        return 1;
    }

    return 0;   
}
int tsp(int *g,int n)
{
    int upper=INT_MAX,i,j;
    qnode *livenode=NULL,*deadnode=NULL;
    
    node *newnode,*enode,*ansn=NULL;
    newnode=(node *)malloc(sizeof(node));
    
    newnode->level=1;
    newnode->parent=NULL;
    newnode->vno=0;
    
    int *r=(int*)malloc(n*n*sizeof(int));
    copy(g,r,n);
    int cost=rcm(r,n);
    newnode->lower=cost;
    newnode->rcm=r;
    
    enqueue(&livenode,newnode);
   
    
    while(!empty(livenode))
    {
       
        enode=dequeue(&livenode);
        if(enode->lower<=upper)
        {
            for(i=0;i<n;i++)    
            {
                if(enode->rcm[enode->vno*n+i]!=INT_MAX)
                {
                    newnode=(node *)malloc(sizeof(node));
                    r=(int *)malloc(n*n*sizeof(int));
                    copy(enode->rcm,r,n);
                    for(j=0;j<n;j++)
                    {
                        r[enode->vno*n+j]=INT_MAX;
                        r[j*n+i]=INT_MAX;
                    }
                    r[i*n]=INT_MAX;
                    cost=rcm(r,n);
                    newnode->parent=enode;
                    newnode->level=enode->level+1;
                    newnode->lower=enode->lower+enode->rcm[enode->vno*n+i]+cost;
                    newnode->rcm=r;
                    newnode->vno=i;
                    
                  
                    if(newnode->level==n)
                    {
                        if(newnode->lower<upper && g[newnode->vno*n]!=INT_MAX)
                        {
                            if(ansn!=NULL)
                            {
                                free(ansn->rcm);
                                free(ansn);
                            }
                         
                            upper=newnode->lower;
                            ansn=newnode;
                        }
                        else
                        {
                            free(newnode->rcm);
                            free(newnode);
                        }
                    }
                    else
                    {
                        enqueue(&livenode,newnode);
                    }
                }
            }
            enqueuedead(&deadnode,enode);
        }
    }
    if(ansn!=NULL)
    {
        
        free(ansn->rcm);
        free(ansn);
    }
    
    while(!empty(deadnode))
    {
        newnode=dequeue(&deadnode);
       // printf("%d ",newnode->lower);
        free(newnode);
    }
   return upper;
}
int main()
{
    int ch,i,n,j;
    int *graph=NULL;
    int t;
    scanf("%d",&t);
    do
    {
        scanf("%d",&n);
        if(graph!=NULL)
            free(graph);
        
        graph=(int*)malloc(n*n*sizeof(int));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                graph[i*n+j]=INT_MAX;
        
        input(graph,n);     
        printf("%d\n",tsp(graph,n));
    }while(--t);
}