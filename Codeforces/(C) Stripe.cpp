#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int t,z,i;
    long long sum=0,count=0;
    scanf("%d",&t);
    
    for( i=0;i<t;i++)
    {
        scanf("%d",&z);
        sum+=z;
        v.push_back(z);
    }
    if(i<2||sum%2!=0){printf("0\n");return 0;}
    
    sum=sum/2;
    if(sum==v[0])count++;
    for(i=1;i<t-1;i++)
    {
        v[i]+=v[i-1];
        if(v[i]==sum)
        count++;
    }
   printf("%d\n",count);
    return 0;
}
