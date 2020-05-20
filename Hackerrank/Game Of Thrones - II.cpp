#include "bits/stdc++.h"
#define mod 1000000007
using namespace std;
#define ll long long int

ll ans=1,count=0,count1=1;
long long int fact[50000];
long long int inverse[50000];

long long int calc_inverse(long long int x,long long int y)
{
	if (y==0)
	{
		return 1;
	}
	long long int res;
	if (y%2==0)
	{
		res=calc_inverse(x,y/2);
		return (res*res)%mod;
	}
	else
		return (x*calc_inverse(x,y-1))%mod;

}
void calc()
{
	fact[0]=fact[1]=1;
	inverse[1]=inverse[0]=1;
	for (long long int i = 2; i < 50000; ++i)
	{
		fact[i]=(i*fact[i-1])%mod;
		//inverse[i]=calc_inverse(fact[i],mod-2);
	}
}
int main() 
{
    calc();
    char s[100010];
    scanf("%s",s);
  int len=strlen(s);
    int i,j,k;
    // Write code to compute the final answer (ans) using the string s
    
    int arr[26]={0};
    for(i=0;i<len;i++)
        {
        arr[s[i]-'a']++;
    }
 ll count=0;
    for(i=0;i<26;i++)
        {
        arr[i]=arr[i]/2;
      //  cout<<arr[i]<<" ";
        count+=arr[i];
        count1=(count1*fact[arr[i]])%mod;
    }
    

    
    ans=(fact[count]*calc_inverse(count1,mod-2))%mod;
    
    cout<<(ans)<<endl;
    return 0;
}
