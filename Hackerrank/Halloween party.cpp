#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int t;
    cin>>t;
    
    while(t--)
        {long long int k;
        cin>>k;
         if(k%2==0)
             {
             long long int n=k/2;
             cout<<n*n<<endl;
         }
         else
             {
            long long int n=k/2;
             cout<<n*(n+1)<<endl;
         }
    }
    return 0;
}
