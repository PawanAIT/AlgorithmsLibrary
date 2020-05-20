#include "bits/stdc++.h"
#define ll __int64

using namespace std;
ll bb[25];
inline ll get(){ll c;ll n = 0;while ((c = getchar()) >= '0' && c <= '9')n = (n << 3) + ( n << 1 ) + c - '0';return n;}

inline void coutt(ll ans){if(!ans){putchar('0');return;}ll k = 0;while(ans){bb[k] = char((ans%10)+'0');++k;ans/=10;}for(int i=k-1;i>=0;--i)putchar(bb[i]);}

int main(){
	std::ios::sync_with_stdio(false);
	ll n;
	std::vector<int> v;
    cin>>n;
    if(n==1){
        putchar('1');
        return 0;
    }
    cout<<n<<" ";
    int t=n,x=n;
    for (int i = x-1; i >1; --i)
    {
    	 if(n%i==0)
    	 	{
    	 		v.push_back(i);
    	 		n=i;
    	 	}
    }
    //sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); ++i)
    {
    	cout<<v[i]<<" ";
    }
    
    cout<<1<<endl;

}
