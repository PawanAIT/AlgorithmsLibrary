#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
  int t,x,marks;
    char str[100];
    map<string,int>v;
    cin>>t;
    while(t--)
        {
        scanf("%d%s",&x,str);
        if(x==1)
            {
            scanf("%d",&marks);
            v[str]+=marks;
        }
            else if(x==2)
                {
                v.erase(str);
            }
            else
                cout<<v[str]<<endl;
            
    }
    return 0;
}
