#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

     int t,x;
    cin>>t;
    while(t--)
        {
        int count =0,rem=0,temp;
        cin>>x;
        
            rem=x%3;
          if(rem==1&&x>=10)
              {
              
                  {
                  temp=x/3;
                  temp=temp-3;
                  for(int i=0;i<temp;i++)
                      {
                      cout<<"555";
                  }
                  cout<<"3333333333"<<endl;
              }
          }
           else if(rem==2&&x>3)
                {
                temp=x/3;
                temp--;
                for(int i=0;i<temp;i++)
                      {
                      cout<<"555";
                  }
                  cout<<"33333"<<endl;
            }
            else if(rem==0)
                {
                temp=x/3;
                 for(int i=0;i<temp;i++)
                      {
                      cout<<"555";
                  }
                cout<<endl;
            }
            else
                cout<<"-1"<<endl;
            
        }
        
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
