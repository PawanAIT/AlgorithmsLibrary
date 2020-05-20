#include "bits/stdc++.h"
#define ll __int64
using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
ll bb[25];
inline void coutt(ll ans)
{
    
    if(!ans){
        putchar('0');
        return;
    }
    ll k = 0;
    while(ans)
    {
        bb[k] = char((ans%10)+'0');
        ++k;
        ans/=10;
    }
    for(int i=k-1;i>=0;--i)
        putchar(bb[i]);
}

 ll Query[1000005];
 int arr[1000005]; 
int freq[1000005];
ll ans,block;
struct node
{
    int x,y,idx;
};

void add(int x)
{
    freq[x]++;
   ans+=freq[x]*freq[x]*x-(freq[x]-1)*(freq[x]-1)*x;
}
void remove(int x)
{
    freq[x]--;
    ans+=freq[x]*freq[x]*x-(freq[x]+1)*(freq[x]+1)*x;
}


bool cmp(node m,node n)
{
    if (m.x/block!=n.x/block)
    {
        return m.x/block < n.x/block;
    }
    return m.y < n.y;
}

int main()
{    
    //MO's algo
    ios::sync_with_stdio(0); cin.tie(0);
    int n,Q;
    n=get(); Q=get();
    block=(int)sqrt(n);
   
    for (int i = 0; i <n; ++i)
       {
        arr[i]=get();
       } 
    
    
    node *N=(node*)malloc(sizeof(node)*Q);
    for (int i = 0; i < Q; ++i)
    {
    	N[i].x=get(),N[i].y=get();
      // scanf("%d%d",&N[i].x,&N[i].y);
      N[i].x--,N[i].y--;
       N[i].idx=i;
    }
    sort(N,N+Q,cmp); // sort acc. to MO's sequence

    int L,R,CurL=0,CurR=-1;

    for (int i = 0; i < Q; ++i)
    {
        L=N[i].x,R=N[i].y;
        while(CurL < L)
        {
                remove(arr[CurL]);
              CurL++;
        }
        while(CurL > L)
        {
                CurL--;
              add(arr[CurL]);
            
        }
        while(CurR < R)
        {  
             CurR++;
            add(arr[CurR]);  
           
        }
        while(CurR > R)
        {    
            remove(arr[CurR]); 
            CurR--;   
        }

        Query[N[i].idx]=ans;
    }

     for (int i = 0; i < Q; ++i)
     {
          coutt(Query[i]);
          putchar('\n');
     }
     free(N);
    return 0;
}
