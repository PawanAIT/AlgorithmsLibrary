#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,k;
    cin>>t;
    vector<int>v;
    for (int i = 0; i < t; ++i)
    {
    	cin>>k;
    	v.push_back(k);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < t; ++i)
    {
    	cout<<v[i]<<" ";
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
