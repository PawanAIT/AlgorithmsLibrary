#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int greatestCommonDivisor(int m, int n)
{
    int r;

    /* Check For Proper Input */
    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;

    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(true);

    return n;
}
int main() {
   int t,n,arr[100000],i;
    cin>>t;
    while(t--)
        {
        cin>>n;
        for(i=0;i<n;i++)
            {
            cin>>arr[i];
        }
        for(i=0;i<n-1;i++)
            {
            if(arr[i+1]>arr[i])
          
            arr[i+1]=greatestCommonDivisor(arr[i], arr[i+1]);
            
           
            else
                {
                swap(arr[i+1],arr[i]);
                arr[i+1]=greatestCommonDivisor(arr[i], arr[i+1]);
    
            }
             
        }
      if(arr[i]>1)
          cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
