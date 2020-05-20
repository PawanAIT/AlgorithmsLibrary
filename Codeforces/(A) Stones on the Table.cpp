#include "iostream"
#include "math.h"
#include <stack>
#include "stdio.h"
#include <vector>
using namespace std;
int main()
{
	char str[100];
	int t,j=0;
	char k,h='`';
	cin>>t;
	cin>>str;
	for (int i = 0; i < t; ++i)
	{
		k=str[i];
		
		if(k!=h)
			j++;
		h=k;
	}
	cout<<t-j;

}
