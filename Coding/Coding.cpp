#include "bits/stdc++.h"
using namespace std;
const int N = 1000;
int dp[N][N];
int EggDropping(int Floors, int Eggs){
	if(Eggs == 1)
		return Floors;
	if(Floors <= 1)
		return Floors;
	
	if(dp[Floors][Eggs] != 0)
		return dp[Floors][Eggs];
	int ans = INT_MAX;
	for(int i = 1; i <= Floors; i++){
		int x = max(1 + EggDropping(Floors - i, Eggs) , 1 + EggDropping(i - 1 , Eggs - 1));
		ans = min(ans , x);
	}
	dp[Floors][Eggs] = ans;
	return ans;
}
int main() {
	cout << EggDropping(100 , 2);
	return 0;
}
