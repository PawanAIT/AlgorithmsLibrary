#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{    
    ios::sync_with_stdio(0); cin.tie(0);
    int m,n;
    std::vector<pair<int,int> > v;
    int arr[100000]={0}; 
    cin>>m>>n;
    for (int i = 1; i <=m; ++i)
    {
       for (int j=i+1; j<i+1+n; j++)
       {
           v.push_back(make_pair(i,j%m));
           arr[i]++,arr[j%(m)]++;
           if (arr[i]>2*n||arr[j%m]>2*n)
           {
                cout<<-1;
                return 0;
           }
       }
    }
    ll sum=0;
    if (n > (m-1)/2)
    {
        cout<<-1;
        return 0;
    }
    cout<<m*n<<endl;
    for (int i = 0; i < v.size(); ++i)
    {
        printf("%d %d \n",v[i].first,(!v[i].second?m:v[i].second));
    }
     
    return 0;
}
