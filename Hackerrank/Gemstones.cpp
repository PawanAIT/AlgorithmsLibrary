#include<iostream>
using namespace std;
int main()
{
	int a[26]={0},x,y,j=0,i,sum=0;
	char arr1[100000],arr[1000000];
 cin>>x;
	cin>>arr;
	for(i=0;arr[i]!='\0';i++)
	{
		a[arr[i]-'a']++;
	}

	
 while(x---1)
 		{
 			int b[26]={0};
 			cin>>arr1;
 			for(i=0;arr1[i]!='\0';i++)
	{
		b[arr1[i]-'a']++;
	}
	
 		for(i=0;i<26;i++)
 		{
 			 if((a[i]>b[i]))
 			a[i]=b[i];
 			
 		
 		}
 	
 		}
 		
 	for(i=0;i<26;i++)
 		{
 		  if(a[i]>0)
 		  {
 		  	sum+=a[i];
 		  }
}
	cout<<sum;
    return 0;
}
