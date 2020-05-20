#include "bits/stdc++.h"
#define ll __int64
using namespace std;
inline ll get(char arr[])
{
    ll c;  
    ll i=0;      
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
         {
            if(c=='0'&&i==0);
            else
                arr[i++]=c;
         }
     arr[i]='\0';
    return i;
}
int main()
{
    char a[1000005],b[1000005];
    int x=get(a);
    int y=get(b);
    if (x>y)
    {
        cout<<'>'<<endl;
    }
    else if(x<y)
    {
        cout<<'<'<<endl;
    }
    else
    {
    if(strcmp(a,b)>0)
        cout<<">";
   else if(strcmp(a,b)<0)
        cout<<"<";
    else
        cout<<"=";
    }

}
