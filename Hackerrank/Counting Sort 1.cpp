#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int arr[100]={0},x,y;
    cin>>x;
    while(x--)
        {
        cin>>y;
        arr[y]++;
    }
    for(int i=0;i<100;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}
