#include<bits/stdc++.h>
using namespace std;
#define ll __int64
int k[500010];
int main()
{
    vector<int>v;
    int t,z,i,j;
   ll sum=0,count=0;
    scanf("%d",&t);
    
    for( i=0;i<t;i++)
    {
        scanf("%d",&z);
        sum+=z;
        v.push_back(z);
    }
    if(i<3||sum%3!=0){printf("0\n");return 0;}    
    sum=sum/3;
ll temp=0;
    for(i=t-1;i>0;i--)
    {
        temp+=v[i];
       k[i]=(temp==sum)?k[i+1]+1:k[i+1];
    }
    temp=0;

    for (int i = 0; i < t; ++i)
    {
        temp+=v[i];
        if (temp==sum)
        {
            count+=k[i+2];
        }
    }
  printf("%I64d\n",count);
    return 0;
}
