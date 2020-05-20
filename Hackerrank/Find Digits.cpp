#include <iostream>

using namespace std;


int main() {
   long int x,y,count=0,z,m;
    cin>>x;
    
    for(int i=0;i<x;i++)
        {count=0;
      cin>>y;
        z=y;
        while(z)
        { 
           m=z%10;
            
			if(m!=0)
			if(y%m==0)
            
                {
                count++;
            }
            z=z/10;
          
        }
      cout<<count<<endl;    
    }
    
    return 0;
}
