#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
 long long  int n,k,A[1000000],min=INT_MAX,i;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>A[i];
    
    sort(A,A+n);
    for(i=0;i+k-1<n;i++)
        {
        if(min>A[i+k-1]-A[i])min=A[i+k-1]-A[i];
    }
    cout<<min;
    return 0;
}
