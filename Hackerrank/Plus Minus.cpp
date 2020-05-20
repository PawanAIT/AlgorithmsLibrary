#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int t;
    cin>>t;
    float arr[t],pos=0,neg=0,zer=0;
    for(int i=0;i<t;i++)
        {
        cin>>arr[i];
        if(arr[i]>0)
            pos++;
        else if(arr[i]==0)
            zer++;
            else neg++;
    }
    cout<<pos/t<<endl;
    cout<<neg/t<<endl;
    cout<<zer/t<<endl;
    return 0;
}
