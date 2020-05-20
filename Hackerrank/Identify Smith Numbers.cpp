#include "bits/stdc++.h"
using namespace std;
int x(int a)
{
	int j=0;
	
	j=a;
	int k=0;
	while(j) {

		    	k+=j%10;
		    	j=j/10;
		    }

	int t=0;

	for (int i = 2;  i*i<=a; ++i)
	{
		while(a%i==0) 
		{
		    a=a/i;
		    j=i;
		    while(j) {
		    	t+=j%10;
		    	j=j/10;
		    }

		  
		}
	}
	while(a) {
		    	t+=a%10;
		    	a=a/10;
		    }
	
	if(t==k)
		return 1;
	else
		return 0;
	
}


int main(int argc, char const *argv[])
{
	int a;
	cin>>a;
    if(a>1)
	cout<<x(a);
    else
        cout<<0;
	return 0;
}
