#include<bits/stdc++.h>
using namespace std;
#define ll __int64
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
int main()
{
    int n,t=0,m=0;
    n=get();
    int a[100][100],b[55][55]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=get();
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][a[i][j]]++;
            b[j][a[i][j]]++;
            t++,m--;
        }
    }
    int max,max1,j,d=n,count=0;
    for(int i=0;i<=51&&count<n;i++)
    {
        max=0;
        max1=b[i][0];
        for(j=0;j<=51;j++)
        {
            if(b[i][j]>max1)
            {
                max=j;
                m++;
            }
        }
        if(max!=0)
        {
            cout<<max<<" ";
            count++;
            t++,m--;
        }
        else
        {
            cout<<d<<" ";
            d=d-1;
            count++;
            t--,m++;
        }
    }
}
