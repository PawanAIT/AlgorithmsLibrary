#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int rc[8][8]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
int arr[9][9];
int visited[9][9];
char a,b,c,d;
int A,B,C,D;
int ANS;
int check(int A,int B)
{
    if (visited[A][B]||(A<1||B<1||A>8||B>8))   
        return 0;  
        else
        return 1; 
   
}
int ans(int x,int y)
{
            queue<pair<int,int> >v;
            v.push(make_pair(x,y));
            pair<int,int> k;
            int m,n;
            while(!v.empty())
            {
                k=v.front();
                 m=k.first,n=k.second;
                 if(m==C&&n==D)return visited[m][n];
                v.pop();
                for (int i = 0; i < 8; ++i)
                {
                    if (check(m+rc[i][0],n+rc[i][1]))
                    {
                        visited[m+rc[i][0]][n+rc[i][1]]=visited[m][n]+1;
                       v.push(make_pair(m+rc[i][0],n+rc[i][1]));
                    }
                }
            }
}
int main()
{   
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
        cin>>a>>b;
        cin>>c>>d;
        A=a-'a'+1; B=b-'0';
        C=c-'a'+1; D=d-'0';
        cout<<ans(A,B)<<"\n";
        
        //cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    }
    return 0;
} 
