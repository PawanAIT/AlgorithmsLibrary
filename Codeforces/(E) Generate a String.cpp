#include<bits/stdc++.h>
using namespace std;
#define ll __int64
 ll arr[2*1000*1000*10+7];
int main()
{
ll n;
ll x,y;
cin>>n>>x>>y;
arr[1]=x;
arr[2*1]=y;
    for(ll i=2;i<=n;i++)
    {
        arr[2*(i-1)]=arr[i-1]+y;
         ll j=2*(i-1);
        for (ll k=0;k<10; ++k)
         {
             if(j-k >= 0)
            {
                if(arr[j-k] > 0 )
                 arr[j-k] = min(arr[j-k],arr[j]+k*x);   
             else
             {
                arr[j-k]=arr[j]+k*x;
             }
            } 
            else
             {
                break;
             }
         }
        
        if(arr[i]>0)
        arr[i]=min(arr[i],arr[i-1]+x);
        else
        {
           arr[i]=arr[i-1]+x;
        }
       
    }
   

     cout<<arr[n]<<endl;
}
