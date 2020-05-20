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
#define bitcount __builtin_popcount
#define INF 2000000000
#define EPS 1e-9

template<typename T>T absll(T X)
{
    if(X<0)
        return -1*X;
    else
        return X;
}

string str;

class Manacher
{
	private:
		int *p;
		string s;
		string t;
	public:
		string preprocess(string s)
		{
			t.resize(2*s.length()+3,'$');
			//cout<<t<<endl;
			t[s.length()*2+2]='@';
			for(int i=0;i<s.length();i++)
			{
				t[2*i+1]='#';
				t[2*i+2]=s[i];
			}
			t[s.length()*2+1]='#';
			return t;
		}
		LL TotalPalindromeness()
		{
			LL totv=0;
			for(int i=0;i<t.length();i++)
			{
				totv+=p[i];
			}
			return totv;
			//cout<<endl;
		}
		Manacher(string s)
		{
			this->s=s;
			t=preprocess(s);
			p=new int[t.length()];
			int center=0,right=0;
			
			for(int i=1;i<t.length()-1;i++)
			{
				int mirror=2*center-1;
				while(t[i+(1+p[i])]==t[i-(1+p[i])])
                {
                	p[i]++;
                }
                if(i+p[i]>right) 
                {
                	center=i;
                	right=i+p[i];
            	}
			}
		}
		
		string LongestPalindromicSubstring()
		{
			int length=0;
			int center=0;
			for (int i=1;i<t.length()-1;i++) 
			{
            	if (p[i]>length)
            	{
                	length=p[i];
                	center=i;
        		}
        	}
        	return s.substr((center-1-length)/2,(center-1+length)/2);
		}
		
		string LongestPalindromicSubstring(int i) 
		{
			i=i+2;
        	int length=p[i];
        	int center=i;
        	return s.substr((center-1-length)/2,(center-1+length)/2);
    	}
};

int main() 
{
	string str="ababababccfhgvhgv";
	Manacher M(str);
	cout<<M.LongestPalindromicSubstring()<<endl;
	return 0;
}