#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define LD long double
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MOD 1000000007
#define MAXN 100005
#define bitcount _builtin_popcount
#define INF 2000000000
#define EPS 1e-9
#define PI 3.14159265359

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

vector<complex<double> > w;
static LL FFT_N;

void init_fft(LL N)
{
	FFT_N=N;
	w.resize(N);
	double ang=2.000*PI/(N*1.000);
	for(LL i=0;i<N;i++)
	{
		w[i]=complex<double>(cos(i*ang),sin(i*ang));
	}
}

void fft(vector<complex<double> > &a)
{
	LL n=(LL)a.size();
	if(n==1)
	{
		return;
	}
	
	LL half=n/2LL;
	vector<complex<double> > even(half),odd(half);
	
	for(LL i=0,j=0;i<n;i+=2,++j)
	{
		even[j]=a[i];
		odd[j]=a[i+1];
	}
	
	fft(even);
	fft(odd);
	
	for(int i=0,fact=FFT_N/n;i<half;++i)
	{
		complex<double> temp=odd[i]*w[i*fact];
		a[i]=even[i]+temp;
		a[i+half]=even[i]-temp;
	}
}

vector<LL> polymul(const vector<LL>& a,const vector<LL>& b)
{
	vector<complex<double> >aaa(a.begin(),a.end()),bbb(b.begin(),b.end());
	vector<LL> res;
	LL n=1LL;
	
	while(n<2*max(a.size(),b.size()))
	{
		n*=2LL;
	}
	
	aaa.resize(n);
	bbb.resize(n);
	
	init_fft(n);
	fft(aaa);
	fft(bbb);
	
	for(size_t i=0;i<n;i++)
	{
		aaa[i]=conj(aaa[i]*bbb[i]);
	}
	
	fft(aaa);
	res.resize(n);
	
	for(size_t i=0;i<n;i++)
	{
		res[i]=(LL)(aaa[i].real()/n+0.50000);
		res[i]%=MOD;
	}
	res.resize(max(a.size()+1,b.size()+1));
	return res;
}