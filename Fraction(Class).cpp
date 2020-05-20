#include<bits/stdc++.h>
using namespace std;
#define LL unsigned long long
#define mp make_pair
#define pb push_back
#define gc getchar_unlocked
#define pc putchar_unlocked

LL gcd(LL A,LL B)
{
	if(B==0)
	return A;
	else return gcd(B,A%B);
}

class Fraction
{
	LL N,D;

	public:

	Fraction()
	{
		N=0;D=1;
	}

	Fraction(LL A,LL B)
	{
		N=A;
		D=B;
	}

	LL getNumerator()
	{
		return N;
	}
	
	LL getDenominator()
	{
		return D;
	}
	
	friend Fraction operator +(Fraction A,Fraction B)
	{
		Fraction C;
		C.D=A.D*B.D;
		C.N=A.N*B.D+A.D*B.N;
		int G=gcd(C.N,C.D);
		C.D/=G;
		C.N/=G;
		return C;
	}

	friend Fraction operator -(Fraction A,Fraction B)
	{
		Fraction C;
		C.D=A.D*B.D;
		C.N=A.N*B.D-A.D*B.N;
		int G=gcd(C.N,C.D);
		C.D/=G;
		C.N/=G;
		return C;
	}

	friend Fraction operator *(Fraction A,Fraction B)
	{
		Fraction C;
		C.D=A.D*B.D;
		C.N=A.N*B.N;
		int G=gcd(C.N,C.D);
		C.D/=G;
		C.N/=G;
		return C;
	}

	friend Fraction operator /(Fraction A,Fraction B)
	{
		Fraction C;
		C.D=A.D*B.N;
		C.N=A.N*B.D;
		int G=gcd(C.N,C.D);
		C.D/=G;
		C.N/=G;
		return C;
	}

	friend istream &operator>>(istream &din,Fraction &A)
	{
		din>>A.N>>A.D;
		return din;
	}
	friend ostream &operator<<(ostream &dout,Fraction &A)
	{
		if(A.N==0)
		{
			dout<<"0"<<endl;
		}
		else
		{
			dout<<A.N<<"/"<<A.D<<endl;
		}
		return dout;
	}
};

int main()
{
	Fraction A,B;
	cin>>A;
	cin>>B;
	Fraction C=A+B;
	cout<<C;
	return 0;
}
