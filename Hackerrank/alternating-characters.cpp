
#include <iostream>
#include"stdio.h"
#include"string.h"
using namespace std;

int q5(char arr[],int n)
{
int i,count=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==arr[i+1])
		count++;
	}
	return count;
}
int main() {
    char arr[1000000];
	int i,y,j,count=0,k;
    cin>>y;
    for(i=0;i<y;i++)
    {
    	cin>>arr;
    	
    	k=strlen(arr);
    	
    	cout<<q5(arr,k)<<endl;
    }

    return 0;
}
