#include "bits/stdc++.h"
using namespace std;
const int N = 1000;
int dp[N][N];
int EggDropping(int floors, int eggs){
	if(eggs == 1)
		return floors;
	if(floors <= 1)
		return floors;
	
	if(dp[floors][eggs] != 0)
		return dp[floors][eggs];
	int ans = INT_MAX;
	for(int i = 1; i <= floors; i++){
		int x = max(1 + EggDropping(floors - i, eggs) , 1 + EggDropping(i - 1 , eggs - 1));
		ans = min(ans , x);
	}
	dp[floors][eggs] = ans;
	return ans;
}
int main() {
	cout << EggDropping(100 , 2);
	return 0;
}
