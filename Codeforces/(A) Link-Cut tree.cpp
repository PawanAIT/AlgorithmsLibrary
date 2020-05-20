#include<bits/stdc++.h>
using namespace std;

int main() 
{
 ios::sync_with_stdio(false);
   long long int t,i,j,temp=1;
   cin>>t>>i>>j;
  int flag=0;
   while(temp<=i)
   {
    if (temp>=t&&temp<=i)
    {
      flag=1;
     cout<<temp<<" ";
    }
    if((double)temp*(double)j>1e18)break;
    temp=temp*j;  
    
   }
   if (flag==0)
   {
   cout<<-1;
   }
    return 0;
    }
    
