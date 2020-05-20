#include<bits/stdc++.h>
using namespace std;
#define ll long long int
template<typename T>
inline void get(T *a)
{
 register char c=0;
 while (c<33) c=getchar();//_unlocked();
 *a=0;
 int tmp = 0;
 while (c>33)
 {
     if ( c == 45 ) tmp = 1;
     else *a=*a*10+c-'0';
     c=getchar();//_unlocked();
 }
 if ( tmp == 1 ) *a = 0-(*a);
}
int main()
{
    char ch;
    long long int n,m,k,i,j,x,y,t;
    get(&n),get(&m),get(&k);
    long long int a[n][m],r[n],c[m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            get(&a[i][j]);
            if(i==0)
             c[j]=j;
        }
        r[i]=i;
    }
    while(k--)
    {
        scanf("%c",&ch);
        get(&x),get(&y);
        if(ch=='c') c[x-1]^=c[y-1]^=c[x-1]^=c[y-1];    //swapping :P
        else if(ch=='r')r[x-1]^=r[y-1]^=r[x-1]^=r[y-1]; 
        else printf("%I64d\n",a[r[x-1]][c[y-1]]);
    }      
}
