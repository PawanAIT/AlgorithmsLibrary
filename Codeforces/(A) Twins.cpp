#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t,k,d,sum=0,count=0;
    cin>>t;
    vector<int>v;
    for (int i = 0; i < t; ++i)
    {
    	cin>>k;
        sum+=k;
    	v.push_back(k);
    }
   sort(v.begin(),v.end());
   int sum1=0;
   for (int i = 0; i < t; ++i)
   {
       if((sum)>=sum1)
       {
        count++;
        sum1+=v[t-i-1];
        sum-=v[t-i-1];
       }
       else
        break;
   }
   cout<<count;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
