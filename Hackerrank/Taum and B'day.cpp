#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
   long int t,b,w,x,y,z,cost,cost1,cost2;
    cin>>t;
    while(t--)
        {
        cin>>b>>w>>x>>y>>z;
        cost=b*x+w*y;
        cost1=b*x+w*(x+z);
        cost2=w*y+b*(y+z);
        
        if(cost<cost1&&cost<cost2)
            cout<<cost<<endl;
        else if(cost1<cost&&cost1<cost2)
            cout<<cost1<<endl;
            else
            cout<<cost2<<endl;
        
    }
    return 0;
}
