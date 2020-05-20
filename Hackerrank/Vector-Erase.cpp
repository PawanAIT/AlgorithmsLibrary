#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,k,d;
    cin>>t;
    vector<int>v;
    for (int i = 0; i < t; ++i)
    {
    	cin>>k;
    	v.push_back(k);
    }
    cin>>k;
    v.erase(v.begin()+k-1);
    cin>>k>>d;
    v.erase(v.begin()+k-1,v.begin()+d-1);
    cout<<v.size()<<endl;
    for (int i = 0; i < v.size(); ++i)
    {
    	cout<<v[i]<<' ';
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
