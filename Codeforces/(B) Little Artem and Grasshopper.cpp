#include <bits/stdc++.h>
using namespace std;
#define ll __int64
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
ll bb[25];
inline void coutt(ll ans)
{
    
    if(!ans){
        putchar('0');
        return;
    }
    ll k = 0;
    while(ans)
    {
        bb[k] = char((ans%10)+'0');
        ++k;
        ans/=10;
    }
    for(int i=k-1;i>=0;--i)
        putchar(bb[i]);
}
int main()
{
    int n;
    string ss;
    int a[100000];
    bool v[100000];
    cin>>n;
    cin>>ss;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    v[count]=true;
    while(1){
        int sign;
        if(ss[count]=='>'){
            sign=1;
        }
        else
        sign=-1;
        count+=a[count]*sign;
        
        if(count<0){
            cout<<"FINITE\n";
            return 0;
        }
        if(count>=n){
            cout<<"FINITE\n";
            return 0;
        }
        
        if(v[count]==true){
            cout<<"INFINITE\n";
            return 0;
        } 
        v[count]=true;
    }
    return 0;
}
