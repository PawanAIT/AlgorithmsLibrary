#include "iostream"
#include "vector"
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m,z;
	cin>>n>>m;
	vector <int> v,k;
	for (int i = 0; i < n; ++i)
	{
		cin>>z;
		k.push_back(z);
		v.push_back(i+1);
	}
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		if(	k[i]>m)
			{k.push_back(k[i]-m);
			v.push_back(v[i]);
		}
	}

	cout<<v[v.size()-1];

	return 0;
}
