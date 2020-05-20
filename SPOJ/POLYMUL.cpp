#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
typedef complex<double> base;
vector<base> omega;
long long FFT_N , mod = 1e18;
void init_fft(long long n)
{
  FFT_N  = n;
  omega.resize(n);
  double angle = 2 * PI / n;
  for(int i = 0; i < n; i++)
    omega[i] = base( cos(i * angle), sin(i * angle));
}
void fft (vector<base> & a)
{
  long long n = (long long) a.size();
  if (n == 1)  return;
  long long half = n >> 1;
  vector<base> even (half),  odd (half);
  for (int i=0, j=0; i<n; i+=2, ++j)
    {
      even[j] = a[i];
      odd[j] = a[i+1];
    }
  fft (even), fft (odd);
  for (int i=0, fact = FFT_N/n; i < half; ++i)
    {
      base twiddle =  odd[i] * omega[i * fact] ;
      a[i] =  even[i] + twiddle;
      a[i+half] = even[i] - twiddle;
    }
}
void multiply (const vector<long long> & a, const vector<long long> & b, vector<long long> & res)
{
  vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
  long long n = 1;
  while (n < 2*max (a.size(), b.size()))  n <<= 1;
  fa.resize (n),  fb.resize (n);

  init_fft(n);
  fft (fa),  fft (fb);
  for (size_t i=0; i<n; ++i)
    fa[i] = conj( fa[i] * fb[i]);
  fft (fa);
  res.resize (n);
  for (size_t i=0; i<n; ++i)
    {
      res[i] = (long long) (fa[i].real() / n + 0.5);
    }
}

int main(){
  int t;
  scanf("%d" , &t);
  while(t--){
    int n;
    scanf("%d" , &n);
    vector<long long> a, b ,c;
    int temp = 0;
    for(int i = 0 ; i <= n; i++){
        scanf("%d" ,&temp);
        a.push_back(temp);
    }
    for(int i = 0 ; i <= n ;i++){
        scanf("%d" , &temp);
        b.push_back(temp);
    }
    multiply(a,b,c);
   
    for(int i = 0 ; i < 2 * n + 1 ;i++){
        printf("%lld ", c[i]);
    }
    printf("\n" );
  }
}
