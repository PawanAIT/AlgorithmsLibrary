#include "bits/stdc++.h"
#define ll long long
#define mod 10000
ll arr[1000][1000];
using namespace std;
inline ll get()
{
    ll c;        
    ll n = 0;
    while ((c = getchar()) >= '0' && c <= '9')
          n = (n << 3) + ( n << 1 ) + c - '0';
    return n;
}



int main(){
    
   double a,b,c,d,f,g;
   cin>>a>>b>>c;

  d=(double)sqrt((double)b*b-(double)4.0*a*c);
  f=(double)(-b+d)/((double)2.0*a);
  g=(double)(-b-d)/((double)2.0*a);

  if(f>g)
  {
    printf("%.20lf\n%.20lf",f,g);
  }
  else
     printf("%.20lf\n%.20lf",g,f);


 
}
