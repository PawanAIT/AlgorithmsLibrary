#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int x,m,n,j,y;
    cin>>x;
    while(x--)
        {
        cin>>m>>n;
     
        y=fabs(int (sqrt(m))-int (sqrt(n)));
           if(sqrt(m)==(int)sqrt(m))
            cout<<y+1<<endl;
        else 
            cout<<y<<endl;
     
    }
    return 0;
}
