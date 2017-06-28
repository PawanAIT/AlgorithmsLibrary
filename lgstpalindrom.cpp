// http://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
#include <bits/stdc++.h>
using namespace std;
int n;
const int N=1e3+5;
char A[N];
int expand(int k,int odd)
{
	int i=k,j=k+odd;
	while(1)
	{
		if(i<0||j>=n)break;
		if(A[i]==A[j])
			i--,j++;
		else
			break;
	} 
	return j - i  - 1 ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0,index;
		scanf("%s",A);
		n=strlen(A);
		bool EVEN=false;
		for (int i = 0; i < n; ++i)
			{
				int oddl = expand(i,0); // odd length
				int evenl = expand(i,1); // even length
				int maxx =max(oddl,evenl);
				if (ans < maxx)
				{
					ans = maxx;
					index = i;
					EVEN = (maxx==evenl)?1:0;
				}
			}
			int start = index - ans/2 + EVEN;
			for (int i = start; i < start + ans ; ++i)
			{
				printf("%c",A[i]);
			}
			printf("\n");
	}
	return 0;
}