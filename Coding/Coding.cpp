// https://leetcode.com/problems/delete-operation-for-two-strings/
#include "bits/stdc++.h"
#pragma warning(disable:4996)

using namespace std;
const int N = 1000 + 5;
int dp[N][N];
class Solution {
public:
	int MatrixChainOrder(int p[] , int i , int j) {
		
		if (i == j) {
			return 0;
		}
		if (dp[i][j] != 0) {
			return dp[i][j];
		}
		int MinVal = INT_MAX;
		for (int k = i; k < j; k++) {
			int curVal = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
			MinVal = min(MinVal, curVal);
		}
		return dp[i][j] = MinVal;
	}
};
int main() {
	freopen("input.txt","r+", stdin);
	Solution solution;
	int arr[] = { 1, 2, 3, 4, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< solution.MatrixChainOrder(arr, 1, n - 1);
	return 0;
}
