#include "bits/stdc++.h"
#define ll long long int
using namespace std;
ll inversion;
void merge(int arr[],int *L,int *R,int left,int right)
{
	int i=0,j=0,k=0;
	while(i<left and j<right)
	{
		if (L[i]>R[j])
		{
			arr[k++]=R[j++];
			inversion+=left-i;
		}
		else
		{
			arr[k++]=L[i++];
		}
	}
	while(i<left)arr[k++]=L[i++];
	while(j<right)arr[k++]=R[j++];
}
void mergesort(int arr[],int length)
{
	if(length<2) return;
	int mid=length/2;
	int *L=new int[mid];
	int *R=new int[length-mid];
	for (int i = 0; i < mid; ++i)
	{
		L[i]=arr[i];	
	}
	for (int i = mid; i < length; ++i)
	{
		R[i-mid]=arr[i];
	}
	mergesort(L,mid);
	mergesort(R,length-mid);
	merge(arr,L,R,mid,length-mid);
	delete[] L;
	delete[] R;
}
 
int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int length;
		cin>>length;
		string ss;
		map<string,int> map;
		std::vector<string> v;
		for (int i = 0; i < length; ++i)
		{
			cin>>ss;
			v.push_back(ss);
		}
		for (int i = 0; i < length; ++i)
		{
			cin>>ss;
			map[ss]=i;
		}
		int arr[30005];
		for (int i = 0; i < v.size(); ++i)
		{
			arr[i]=map[v[i]];
		}
	
		mergesort(arr,length);
		cout<<inversion<<endl;
		inversion=0;
	}
 
     
	return 0;
} 
