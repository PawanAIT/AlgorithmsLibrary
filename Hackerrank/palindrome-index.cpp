#include<iostream>
#include<string.h>

using namespace std;
int main()
{
	int t;
    cin>>t;
    while(t--)
        {
        int i,j,k,temp,n,flag=0;
	
	char arr[100010];
	
        cin>>arr;
        int len=strlen(arr);
	
	for(i=0,j=len-1;i<len/2;i++,j--)
	{
		 
		if(arr[i]!=arr[j])
		{
			 temp=i;
			 n=j;
			for(k=i+1;k<len/2;k++,n--)
			{
				 
				if(arr[k]!=arr[n])
			{
				temp=j;
				cout<<temp<<endl;
				flag=1;
				break;
			}
		
			}
			if(flag==1)
			break;
			else
			{
					cout<<temp<<endl;
					break;
				}
			
		}
	}

	if(i>=len/2)
	cout<<"-1"<<endl;
        
    }

	return 0;
}
