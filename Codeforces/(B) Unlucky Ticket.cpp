#include "bits/stdc++.h"
#define ll long long int
using namespace std;
int main()
{
    int t=1;int arr[201];
    //scanf("%d",&t);
    while(t--)
    {
        int count,sum=0;
        char ch;
        scanf("%d",&count);
        scanf("%c",&ch);
        
        for (int i = 0; i < 2*count; ++i)
        {
            scanf("%c",&ch);
            arr[i]=ch-48;
        }
        
        sort(arr,arr+count);
        sort(arr+count,arr+2*count);
    
        int k=0,m=0;
        for (int i = 0,j=count; i < count; ++i,j++)
        {
            if (arr[i]>arr[j])
            {
                k++;
                
            }
            else if(arr[i]<arr[j])
                m++;
                  else
{
printf("NO\n");
return 0;
}
        }
        if (k==0||m==0)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");
        
    }

    return 0;
}
