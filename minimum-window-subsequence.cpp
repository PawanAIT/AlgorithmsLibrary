// Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

// If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

// Example 1:

// Input: 
// S = "abcdebdde", T = "bde"
// Output: "bcde"
// Explanation: 
// "bcde" is the answer because it occurs before "bdde" which has the same length.
// "deb" is not a smaller window because the elements of T in the window must occur in order.
 

// Note:

// All the strings in the input will only contain lowercase letters.
// The length of S will be in the range [1, 20000].
// The length of T will be in the range [1, 100].

For substring S[0, i] and T[0, j], 
dp[i][j] is starting index k of the shortest postfix of S[0, i], such that T[0, j] is a subsequence of S[k, i]. 
Here T[0] = S[k], T[j] = S[i]. Otherwise, dp[i][j] = -1.

The goal is the substring with length of min(i-dp[i][n-1]) for all i < m,  where m is S.size() and n is T.size() 
Initial condition: dp[i][0] = i if S[i] = T[0], else -1
Equations: If S[i] = T[j], dp[i][j] = max(dp[k][j-1]) for all k < i; else dp[i][j] = -1;      
O(mn) space 82 ms

class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++) 
            if (S[i] == T[0]) dp[0][i] = i;
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int i = 0; i < m; i++) {
                if (k != -1 && S[i] == T[j]) dp[j][i] = k;
                if (dp[j-1][i] != -1) k = dp[j-1][i];
            }
        }
        int st = -1, len = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[n-1][i] != -1 && i-dp[n-1][i]+1 < len) {
                st = dp[n-1][i];
                len = i-dp[n-1][i]+1;
            }    
        }
        return st == -1? "":S.substr(st, len);
    }
};


The basic idea is simple and based on two pointer:
(1) check feasibility,
(2) check optimization.

class Solution {
    public String minWindow(String S, String T) {
        char[] s = S.toCharArray(), t = T.toCharArray();
        int sindex = 0, tindex = 0, slen = s.length, tlen = t.length, start = -1, len = slen;
        while(sindex < slen) {
            if(s[sindex] == t[tindex]) {
                if(++tindex == tlen) {
                    //check feasibility from left to right of T
                    int end = sindex+1;
                    //check optimization from right to left of T
                    while(--tindex >= 0) {
                        while(s[sindex--] != t[tindex]);
                    }
                    ++sindex;
                    ++tindex;
                    //record the current smallest candidate
                    if(end - sindex < len) {
                        len = end - sindex;
                        start = sindex;
                    }
                }
            }
            ++sindex;
        }
        return start == -1? "" : S.substring(start, start + len);
    }
}