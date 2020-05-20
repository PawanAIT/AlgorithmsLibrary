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
#define MAXN 1000005
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

struct Task
{
	int AT,BT,CT,TAT,WT,pri;
	bool flag;
};

#define MAX_TIME 1999

bool comp(const Task &P,const Task &Q)
{
	return P.pri<Q.pri;
}

int main()
{
	int N;
	cin>>N;
	vector<Task> V(N,{0,0,0,0,0,0,true});
	for(int i=0;i<N;i++)
	{
		cin>>V[i].AT>>V[i].BT>>V[i].pri;
	}
	
	sort(V.begin(),V.end(),comp);
	
	//Starting process
	int c=MAX_TIME;
	for(int i=0;i<N;i++)
	{
		if(V[i].AT<c)
		{
			c=V[i].AT;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(V[j].AT<=c&&V[j].flag)
			{
				V[j].flag=false;
				V[j].CT=c+V[j].BT;
				c=V[j].CT;
				break;
			}
		}
	}
	
	double avg_waiting_time=0.00000;
	double avg_turnaround_time=0.000000;
	for(int i=0;i<N;i++)
	{
		V[i].TAT=V[i].CT-V[i].AT;
		V[i].WT=V[i].TAT-V[i].BT;
		avg_waiting_time+=V[i].WT*1.000000000;
		avg_turnaround_time+=V[i].TAT*1.00000000;
	}
	avg_waiting_time/=N*1.00000;
	avg_turnaround_time/=N*1.000000;
	printf("Avg  WT = %lf\n",avg_waiting_time);
	printf("Avg TAT = %lf\n",avg_turnaround_time);
	return 0;
}