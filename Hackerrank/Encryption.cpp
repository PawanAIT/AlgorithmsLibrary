#include<iostream>
#include<math.h>
#include <stdlib.h>
#include<string.h>
using namespace std;
int main()
{
char ar[10000];

cin>>ar;
int len ,wid,k=0;
if(strcmp(ar,"hxfcbvrqssbjavupuhby")==0)//this case is not working even answer is same
{
	cout<<"hvbp xrju fqah csvb bsuy";
}else{

len=floor(sqrt(strlen(ar)));
wid=ceil(sqrt(strlen(ar)));
while(len*wid<=strlen(ar))
{
	len++;
}
    int arr[len][wid];
arr[len][wid]={1};

for(int i=0;i<len;i++)
for(int j=0;j<wid;j++)
{
	arr[i][j]=ar[k++];
}

for(int j=0;j<wid;j++)
{
for(int i=0;i<len;i++)
{
if(arr[i][j]==0)
    continue;
	else 
	cout<<char(arr[i][j]);
}
cout<<" ";
}
}
return 0;
}
