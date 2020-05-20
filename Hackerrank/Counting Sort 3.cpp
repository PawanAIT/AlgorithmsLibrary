#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int arr[100]={0},x,y,sum=0;
    char paw[10000];
    cin>>x;
    while(x--)
        {
        cin>>y>>paw;
        arr[y]++;
    }
    for(int i=0;i<100;i++)
        {(sum+=arr[i]);
        cout<<sum<<" ";
        }
    return 0;
}
