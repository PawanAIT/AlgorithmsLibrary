#include "bits/stdc++.h"
#define ll __int64
using namespace std;
int power(int x,int y)
{
    return (y?(y%2==1?x:1)*power(x*x,y/2):1);
}
int main()
{ ios::sync_with_stdio(false);
int t,i=0,arr[10];
cin>>t;
while(t)
{
    arr[i++]=t%10;
    t=t/10;
}
std::vector<int> v;

for (;;)
{
    int flag=0,x=0;
        for (int k = 0; k < i; ++k)
        {
            if (arr[k]>0)
            {
                x+=power(10,k);
                arr[k]--;
                flag++;
            }
            
        }
        if(x>0)
        v.push_back(x);
        if (flag==0)
        {
            break;
        }
}
sort(v.begin(),v.end());
printf("%d\n",v.size());
for (int i = 0; i < v.size(); ++i)
{
    printf("%d ",v[i]);
}


    return 0;
}
