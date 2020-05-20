#include "bits/stdc++.h"
#define ll __int64
#define mod 1000003
using namespace std;
ll t(ll x)
{
	if (x==0)
	{
		return 1;
	}
	if (x%2==0)
	{
		ll y=t(x/2);
		return (y*y)%mod;
	}
	else
		return (2*t(x-1))%mod;
}

int main(int argc, char const *argv[])
{
	string str,m;
	cin>>str;
	std::map<char,string> map;
map['>']="1000";
map['<']="1001";
map['+']="1010";
map['-']="1011";
map['.']="1100";
map[',']="1101";
map['[']="1110";
map[']']="1111";

for (int i = 0; str[i]; ++i)
{
	m.append(map[str[i]]);
}
int x=m.length();
ll sum=0;

for (int i=0 ; i<x; i++)
{
	if (m[i]=='1')
	{
		
		sum=(sum+t(x-1-i))%mod ;
	}

	
	
	
}
printf("%I64d\n",sum );
	return 0;
}
