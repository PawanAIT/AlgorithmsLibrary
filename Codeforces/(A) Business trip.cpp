#include "bits/stdc++.h"
#define ll long long int
using namespace std;
int main()
{
    int t=1,arr[13];
    //scanf("%d",&t);
    while(t--)
    {
        int count,sum=0;
        scanf("%d",&count);
        
        for (int i = 0; i < 12; ++i)
        {
            scanf("%d",arr+i);
        }
        if (!count)
        {
            printf("0\n");return 0;
        }
        sort(arr,arr+12);
        
        for (int i = 0; i < 12; ++i)
        {
            sum+=arr[11-i];
            //printf("%d\n",sum);
            if (sum>=count)
            {
                printf("%d\n",i+1);
                return 0;
            }
        }
        
    }
    printf("-1\n");
    return 0;
}
