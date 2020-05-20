#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
        {
        for(int j=0;j<t-i-1;j++)
            {
            cout<<" ";
            
        }
        for(int m=0;m<i+1;m++)
            cout<<"#";
        cout<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
