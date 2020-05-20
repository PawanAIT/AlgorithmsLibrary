#include "iostream"
#include "math.h"
#include <stack>
#include "stdio.h"
#include <vector>
#include "string.h"
using namespace std;
int main()
{
	char str[100],str1[101];
	int t,j=0;
	char k,h='`';

	cin>>str;
	
	cin>>str1;
	for (int i = 0; i < strlen(str1); ++i)
	{
		if (str[j]==str1[i])
		{
			j++;
		}
	}
	cout<<j+1;

}
