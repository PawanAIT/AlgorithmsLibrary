#include "iostream"
#include "math.h"
#include <stack>
#include <vector>
using namespace std;
int main()
{
	char str[101],k[101];
	int j=0;
	cin>>str;
	for (int i = 0; str[i]!='\0'; ++i)
	{
		if(str[i]==str[i+1]&&str[i]=='/')
			continue;
		else
			k[j++]=str[i];
	}

	for (int i = 0; (k[j-1]=='/')? i< j-1:i<j; ++i)
	{
		
			cout<<k[i];
		
	}
			if(j==1)
			cout<<'/';

}
