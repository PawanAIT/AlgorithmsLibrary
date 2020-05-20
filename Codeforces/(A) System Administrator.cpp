
#include "bits/stdc++.h"


using namespace std;

int main()
{
		int t;
		cin>>t;
		int m,n,sum=0,k;
		int x1=0,y1=0,x2=0,y2=0;
		while(t--) {
		    cin>>k>>m>>n;
		    if (k==1)
		    {
			    	 x1++;
			    	 y1+=m;
		    }
		    else
		    {
		    	x2++;
		    	y2+=m;
		    }

		   
		}
		(x1*5<=y1)?cout<<"LIVE\n":cout<<"DEAD\n";
		(x2*5<=y2)?cout<<"LIVE":cout<<"DEAD";

}
