#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int countprime(long long int num2)
    {
    
    long long int num1=1, i, j, flag, temp, count = 0;
 
    temp = num1;
    if ( num1 % 2 == 0)
    {
        num1++;
    }
    for (i = num1; i <= num2; i = i + 2)
    {
        flag = 0;
        for (j = 2; j <= sqrt(i); j++)
        {
            if ((i % j) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
         
            count++;
        }
    }
  return count;
}

int main() {
    int t,i;
    cin>>t;
    
    while(t--)
        {
      
       long long int arr[10000],n;
        cin>>n;
        for(i=0;i<=n;i++)
            {
            if(i<4)
                arr[i]=1;
            else
                arr[i]=arr[i-1]+arr[i-4];
        }
        if(arr[n]==1)
            cout<<0<<endl;
        else
        cout<<countprime(arr[n])<<endl;
            
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
