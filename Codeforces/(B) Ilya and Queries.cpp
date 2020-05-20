#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,w,x,arr[100000],i;
    char str[100000];
    scanf("%s",str);
    w=strlen(str);
    for(i=1;i<=w;i++)
    {
        if(str[i]==str[i-1])
        {
            arr[i]=arr[i-1]+1;
        }
        else
        {
            arr[i]=arr[i-1];
        }
    }
    
    scanf("%d",&t);
    
    while(t--)
    {
    
        scanf("%d %d",&w,&x);
        printf("%d \n",arr[x-1]-arr[w-1]);
    }
    return 0;
}
