#include <cmath>
#include <cstdio>
#include<string.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




int main() {

   int arr[10000],arr1[10000];
   int t,i,count1=0,count2=0,sum=0;
cin>>t;
   for(i=0;i<t;i++)
   {
        cin>>arr[i]>>arr1[i];
        if(arr[i]==0)
        count1++;
        if(arr1[i]==0)
        count2++;

   }
   if(t-count1>count1)
   sum+=count1;
   else
   sum+=t-count1;

  if(t-count2>count2)
   sum+=count2;
   else
   sum+=t-count2;

   cout<<sum;

  return 0;
}
