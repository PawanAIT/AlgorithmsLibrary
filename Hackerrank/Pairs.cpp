#include <iostream>
#include <algorithm>
using namespace std;


int main()
    {
    
    int arr[1000000],n,k,count=0;

    
   cin>>n>>k;
    for(int i=0;i<n;i++)
        {
        cin>>arr[i];
        
    }
    

    sort(arr, arr+n); 
    int l = 0;
    int r = 0;
    while(r<n)
    {
         if(arr[r]-arr[l]== k)
        {
              count++;
              l++;
              r++;
        }
         else if(arr[r]-arr[l]>k)
              l++;
         else
              r++;
    } 


    cout<<count;
    return 0;
}
