#include <iostream>
#include"string.h"
using namespace std;
int main()
{
	char arr[100000];
	int count[26]={0},i=0,y,k=0,l=0;
	cin>>arr;
	while(arr[i]!='\0')
	{	count[arr[i]-'a']++;
	i++;
}
		 
		y=strlen(arr);
		
		if(y%2==0)
		{
			 for(i=0;i<26;i++)
			if(count[i]%2==1)
			 {
			 	cout<<"NO"<<endl;
			 	k=1;
			 	break;
			 }
			 
			 
			 if(k==0)
			 {
			 	cout<<"YES"<<endl;
		}
	}
		else
		{
			for(i=0;i<26;i++)
			 if(count[i]%2==1)
			 l++;
			 
			 if(l>1)
			 {
			 	cout<<"NO"<<endl;
			 }
			 else
			 cout<<"YES"<<endl;
		}
    return 0;
	}
			 
			 
			 
			 
			 
			 
			 
	
	
