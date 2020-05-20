#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,i=0,arr[100000],count=0,k=0;
    cin>>N;
    for(i=0;i<N;i++)
        {
        cin>>arr[i];
    }
    sort(arr,arr+N);
  i=0;
   while(i<N)
        {
        while(arr[i]+4>=arr[k]&& k<N)
            {
            k++;
            continue;
            
        }
        i=k;
        count++;
        }
    cout<<count;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
