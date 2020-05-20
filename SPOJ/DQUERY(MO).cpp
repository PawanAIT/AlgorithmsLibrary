#include "bits/stdc++.h"
#define ll __int64
using namespace std;
 int Query[200005];
 int arr[30005];  
 int freq[1000005]  ;// should be 1000000;
int ans,block;
struct node
{
    int x,y,idx;
};
 
void add(int x)
{
    freq[x]++;
    if (freq[x]==1)
    {
        ans++;
    }
}
void remove(int x)
{
    freq[x]--;
    if (freq[x]==0)
    {
        ans--;
    }
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
    //ios::sync_with_stdio(0); cin.tie(0);
    int n,Q;
    scanf("%d",&n);
    block=(int)sqrt(n);
    
    for (int i = 0; i <n; ++i)
        scanf("%d",arr+i);
    
    scanf("%d",&Q);
    node *N=(node*)malloc(sizeof(node)*Q);
    
   
    for (int i = 0; i < Q; ++i)
    {
       scanf("%d%d",&N[i].x,&N[i].y);
      N[i].x--,N[i].y--;
       N[i].idx=i;
    }
    sort(N,N+Q,cmp);
 
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
            printf("%d\n", Query[i]);
     }
     free(N);
    return 0;
} 
