#include <stdio.h>

int main()
{
     int i,j,max=-1,min=1000010,no,count,t,p=0;
    scanf("%d",&t);
    while(t--)
        {
        int a[1000000]={0};
        max=-1;min=1000010;
        
     scanf("%d",&no);
     for(i=0;i<no;i++)
     {
         scanf("%d",&count);
         a[count]++;
         if(count>max)
         max=count;
         if(count<min)
         min=count;
     }
        int sum=0;
      long long int ans=1;
        long long int ans1=0;
       // printf("%d %d\n", min,max);
        
        if( min!=0 || max>no-1)
        {
            printf("0\n");
        }
        else
         {
            for(j=min;j<=max;j++)
            {
               
             if(a[j]!=0)
             {
                 sum+=a[j];
                 
                 ans*=sum-j;
                ans=ans%1000000007;
                 p=0;
             }
                else
                    {
                     ans*=(sum-j);
                    ans=ans%1000000007;
                }
                    
            }
            for(i=sum-j;i>0;i--)
                  {  ans*=i;
                   ans=ans%1000000007;
                  }
            printf("%lld\n",ans);
         }
        
    }
    return 0;
}
