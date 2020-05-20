#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int y,i=10,loan,k,h;
	cin>>y;
	int n,c,m;
	for(i=0;i<y;i++)
	{
		cin>>n>>c>>m;
		k=n/c;
		h=k;
		do
		{
		loan=h%m;
		k+=(h/m);	
		h=h/m+loan;
		
		}
		
	while(h>=m);
	cout<<k<<endl;
	}
    return 0;
}
