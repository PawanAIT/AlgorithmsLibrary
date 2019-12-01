// From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

// Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

// Example 1:

// Input: source = "abc", target = "abcbc"
// Output: 2
// Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
// Example 2:

// Input: source = "abc", target = "acdbc"
// Output: -1
// Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
// Example 3:

// Input: source = "xyz", target = "xzyxz"
// Output: 3
// Explanation: The target string can be constructed as follows "xz" + "y" + "xz".
 

// Constraints:

// Both the source and target strings consist of only lowercase English letters from "a"-"z".
// The lengths of source and target string are between 1 and 1000.

class Solution {
	vector<vector<int>> next;
public:
	int shortestWay(string source, string target) {
		source = '@' + source;
		int n = source.size();
		next.resize(n, vector<int>(26, -1));
		for (int i = n - 2; i >= 0; i--) {
			next[i] = next[i + 1];
			int sourceindex = source[i + 1] - 'a';
			next[i][sourceindex] = i + 1;
		}
		for (int i = 0; i < target.size(); i++) {
			if (next[0][target[i] - 'a'] == -1)
				return -1;
		}
		int ans = 1;
		int j = 0;

		for (int i = 0; i < target.size(); i++) {
			j = next[j][target[i] - 'a'];
			if (j == -1)ans++, j = next[0][target[i] - 'a'];
		}
		return ans;
	}
};