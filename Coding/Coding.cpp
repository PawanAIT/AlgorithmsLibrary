#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

// https://leetcode.com/problems/shortest-palindrome/

int getPrefixSuffix(string &s) {
	int f[10000 + 5] = { 0 };
	int n = s.size();
	int i = 0, j = 1;
	while (j < n) {
		if (s[i] == s[j]) {
			f[j] = i + 1;
			i++, j++;
		}
		else if (i == 0)
			j++;
		else
			i = f[i - 1];
	}
	return f[n - 1];
}
string shortestPalindrome(string &s) {
	string rev = s;
	reverse(rev.begin(), rev.end());
	string ans = s + '#' + rev;
	int charToadd = getPrefixSuffix(ans);
	return rev.substr(0, s.size() - charToadd) + s;
}
int main() {
	string s;
	cin >> s;
	cout << shortestPalindrome(s);
	return 0;
}

/*
6
7
1 2
2 3
1 3
4 1
4 5
5 6
6 4


"abcd"
"dcba"


"cbaabcd"


"dcbabcd"

*/