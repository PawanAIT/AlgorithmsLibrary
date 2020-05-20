#include "bits/stdc++.h"
using namespace std;
#define ll __int64
#define MAX 1000
int a[1001][1001];
int n=1000;
ll sum=0;
int count=0;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}
void Diagonals() {
	int count=0;
    for (int slice = 0; slice < 2*n - 1; slice++) {
        int z = slice < n ? 0 : slice - n + 1;
        int k = slice < n ? n - slice - 1 : 0;
        count=0;
        for (int j = z; j <= slice - z; j++, k++) {
            if (a[j][k]==1)count++;
        }
       sum+=count*(count-1);
    }
}

void DiagonalsReverse() {
	int count=0;
    for (int slice = 0; slice < 2*n - 1; slice++) {
        int z = slice < n ? 0 : slice - n + 1;
        count=0;
        for (int j = z; j <= slice - z; j++) {
            if (a[j][slice-j]==1)count++;
        }
       sum+=count*(count-1);
    }
}

int main() {
	int t,x,y;
     t=get();
    for (int i = 0; i < t; ++i)
    {
        x=get();
        y=get();
        a[x-1][y-1]=1;
    }
    DiagonalsReverse();
    Diagonals(); 
    cout<<sum/2;
    return 0;
}
