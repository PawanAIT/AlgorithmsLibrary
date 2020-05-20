#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios::sync_with_stdio(0);
    ll t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>m;
        n=m*(m+1)/2;
        for(int i=0;i<63;i++)
        {
            if((1LL<<i)<=m)
                n=n-2*(1LL<<i);
            else
                break;
        }
        cout<<n<<endl;


    }
    return 0;
}
