
#include <iostream>
#include"stdio.h"
#include"string.h"
using namespace std;

int q5(char arr[],int n)
{
long int i,count=0,j=n-1;
	for(i=0;i<n/2;i++,j--)
	{
		if(arr[i]==arr[j])
		continue;
		else
		{
		if(arr[j]>arr[i])
        {
            count+=int(arr[j]-arr[i]);
        }
            else
                count+=int(arr[i]-arr[j]);
			
	}
	
}
return count;
}
int main() 
{
    char arr[1000000],ch;
	long int i,y,j,count=0,k;
    cin>>y;
    for(i=0;i<y;i++)
    {
    	cin>>arr;
    	
    	k=strlen(arr);
    	
    	cout<<q5(arr,k)<<endl;
    }

    return 0;
}
