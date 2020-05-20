#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,temp,i=0,k=0,t1,rem=0;
  
    cin>>t;
      temp=t;
    int arr[100000];
    while(temp!=0)
        {
       arr[k]=temp%10;
        k++;
        temp=temp/10;
    }
    
    while(--t>1)
        {	
        for(i=0;i<k;i++)
            {
            t1=arr[i]*(t)+rem;
           
            arr[i]=(t1)%10;
            rem=t1/10;
            
        }
        
        while(rem)
            {
            arr[k]=rem%10;
            rem=rem/10;
            k++;
        }
      
       
    }
     for(i=k-1;i>=0;i--)
        cout<<arr[i];
    
    return 0;
}
