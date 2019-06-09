// https://leetcode.com/problems/delete-operation-for-two-strings/
#include "bits/stdc++.h"
#pragma warning(disable:4996)

using namespace std;
const int N = 1000 + 5;
int dp[N][N];
class Solution {
public:
	int minDistance(string word1, string word2) {
		memset(dp, 0, N * N);
		for (int i = 1; i <= word1.size(); i++) {
			for (int j = 1; j <= word2.size(); j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
	}
};
int main() {
	freopen("input.txt","r+", stdin);
	Solution solution;
	string word1, word2;
	cin >> word1 >> word2;
	cout << solution.minDistance(word1, word2);
	return 0;
}
