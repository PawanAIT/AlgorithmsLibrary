#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int t,x,y;
    set<int> v;
    cin>>t;
    while(t--)
        {
        cin>>x>>y;
        if(x==1)v.insert(y);
        else if(x==2)v.erase(y);
        else v.find(y)!=v.end()?cout<<"Yes\n":cout<<"No\n";     
    }
    return 0;
}
