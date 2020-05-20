#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
      long int x,y;
    cin>>x>>y;
    if(x%2==0)
        {
        cout<<(x/2-1)*10+1+(y-1)*2;
    }
    else
        {
        cout<<(x/2)*10+(y-1)*2;
    }
      
    return 0;
}
