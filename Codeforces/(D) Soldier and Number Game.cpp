#include <bits/stdc++.h>
using namespace std;
long long  dp[5000005];
template<typename T>

/* PURANE PAAP */

inline void fi(T *a)
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
void pre()
{
    dp[0] = dp[1] = 0;
    for ( int i = 2; i <= 5000005; i++ ) {
        if ( dp[i] > 0 ) continue;
        for ( int j = i; j <= 5000005; j += i ) {
            int k = j;
            while ( k%i == 0 ) dp[j]++, k /= i;
        }
    }
    for ( int i = 2; i <= 5000005; i++ ) dp[i] += dp[i-1];
    return;
}
int main()
{
    pre();
    int t,a,b;
    fi(&t);
    while ( t-- ) {
        fi(&a), fi(&b);
        printf("%d\n", dp[a]-dp[b]);  //already did this Que.. LOL
    }
    return 0;
} 
