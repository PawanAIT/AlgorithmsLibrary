#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
typedef complex<double> base;
vector<base> omega;
long long  FFT_N ;
 
void init_fft(long long  n)
{
  FFT_N  = n;
  omega.resize(n);
  double angle = 2 * PI / n;
  for(long long  i = 0; i < n; i++)
    omega[i] = base( cos(i * angle), sin(i * angle));
}
void fft (vector<base> & a)
{
  long long  n = (long long ) a.size();
  if (n == 1)  return;
  long long  half = n >> 1;
  vector<base> even (half),  odd (half);
  for (long long  i=0, j=0; i<n; i+=2, ++j)
    {
      even[j] = a[i];
      odd[j] = a[i+1];
    }
  fft (even), fft (odd);
  for (long long  i=0, fact = FFT_N/n; i < half; ++i)
    {
      base twiddle =  odd[i] * omega[i * fact] ;
      a[i] =  even[i] + twiddle;
      a[i+half] = even[i] - twiddle;
    }
}
void multiply (const vector<long long > & a, const vector<long long > & b, vector<long long > & res)
{
  vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
  long long  n = 1;
  while (n < 2*max (a.size(), b.size()))  n <<= 1;
  fa.resize (n),  fb.resize (n);
 
  init_fft(n);
  fft (fa),  fft (fb);
  for (long long  i=0; i< n; ++i)
    fa[i] = conj( fa[i] * fb[i]);
  fft (fa);
  res.resize (n);
  for (long long  i=0; i<n; ++i){
      res[i] = (long long ) (fa[i].real() / n + 0.5);
      res[i] = res[i] ;
    }
}
 
int  main(){
    long long  t = 1;
    scanf("%lld", &t);
    while(t--){
         long long  n , k , a , b , c,temp;
         scanf("%lld %lld %lld %lld" ,&n , &a , &b , &c);
         vector<long long > alpha(1 , 1), beta(1, 1) , gamma(1 ,1) , ans(1 , 1); 
         for(long long  i = 1 ; i <=a; i++)
            alpha.push_back(1);
         for(long long  i = 1; i <= b;i++)
           beta.push_back(1);
       for(long long  i = 1; i <= c;i++)
           gamma.push_back(1);
    
           multiply(alpha , beta , ans);        
           multiply(ans , gamma , ans);
            long long res = 0;
         for(long long  i = 0; i <= min(n, a + b + c) ;i++)
             res += ans[i];
           printf("%lld\n", res);
    }
      
} 
