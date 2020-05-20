#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int arr[1000000];
    int n,k,q,i,c;
    cin>>n>>k>>q;
    for(i=0;i<n;i++)
        cin>>arr[i];
  k=n-k%n;
    for(i=0;i<q;i++)
        {
        cin>>c;
        cout<<arr[((c+k)%n)]<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
