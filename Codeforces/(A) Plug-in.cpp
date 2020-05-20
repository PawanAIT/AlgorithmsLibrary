#include "bits/stdc++.h"
	using namespace std;
	int main(int argc, char const *argv[])
	{
		std::ios::sync_with_stdio(false);
		char ch;
		char arr[200001];
		int i=0;
		while((ch=getchar())!='\n')
		{
			if (i==0)
			{
				arr[i]=ch;
				i++;
			}
			else
			{
				if (ch==arr[i-1])
				{
					i--;
				}
				else
					arr[i]=ch,i++;
			}
		}
		arr[i]='\0';
		cout<<arr;
	return 0;
	}
