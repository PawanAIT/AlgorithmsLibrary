#include<iostream>
using namespace std;
//fibonicci series
int main()
{
	long int d,i,n,j;
	cin>>n;
	for(j=0;j<n;j++)
	{
		long int a=0,b=1,c=0,z=1;
		cin>>d;
	
	for(i=0;i<1000;i++)
	{
	if(c==d)
	{
        cout<<"IsFibo"<<endl;
        z=0;
            break;
            
        }
        
	
	a=b;
	b=c;
	c=a+b;
		
	}
	if(z==1)
	cout<<"IsNotFibo"<<endl;
	

}
return 0;
}

