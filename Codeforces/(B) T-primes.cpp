#include "bits/stdc++.h"
using namespace std;

long long int Get()
{
  char c;while(c=getchar(),c<'0'||c>'9');
  long long int  X=c-48;while(c=getchar(),c>='0'&&c<='9')X=X*10+c-48;
  return X;
}

void prime(int arr[])
{
    int i,j;
    for (i = 2; i <= 1000; ++i)
    {
        for (j = i*i; j < 1000001; j+=i)
        {
            arr[j]=1;
        }
    }

}

int main(int argc, char const *argv[])
{
    
    int arr[1000000]={0},t;
    prime(arr);

    vector<long long int> v;

    for (long long int  i = 2; i < 1000000; ++i)
    {
        if (!arr[i])
        {
            v.push_back(i*i);
        }
    }
    
    long long int w;

    t=Get();
    while(t--)
    {
       w=Get();
    if(sqrt(w)==floor(sqrt(w)))
    {
            if (*lower_bound(v.begin(),v.end(),w)==w)
            {
                cout<<"YES\n";
            
            }
            else
            cout<<"NO\n";
    }
    else
        cout<<"NO\n";
}
    return 0;
}
