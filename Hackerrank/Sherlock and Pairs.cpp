#include<iostream>

using namespace std;

int main(){

   int j; 
 

cin>>j;
    while(j--)
 {
        
        long long int i,s,temp,arr[1000007]={0};
         long long int sum=0;
cin>>s;
 for(i=0;i<s;i++)
      {
	  cin>>temp;
      arr[temp]++;
      }
for(i=0;i<1000007;i++)
      {
    if(arr[i]>=2)
        {
        sum+=arr[i]*(arr[i]-1);
    }
}

cout<<sum<<endl;
      
  
}
   


 return 0;
}

