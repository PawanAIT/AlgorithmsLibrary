#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int dp[N][N];
class Solution {
public:
    bool isMatch(string s, string p) {
    	s = '&' + s;
    	p = '@' + p;
    	memset(dp, 0 ,sizeof(dp));
    	dp[0][0] = 1;
    	for(int i = 1 ; i <= p.size() ;i++)
    		if(p[i]=='*')
    			dp[0][i] = dp[0][i - 2];
        for(int i = 1 ; i <= s.size() ; i++){
        	for(int j = 1 ; j <= p.size(); j++){
        		if(s[i] == p[j] || p[j] == '.'){
        			dp[i][j] = dp[i-1][j-1];
        		}
        		else if(p[j] == '*'){
        			dp[i][j] |= dp[i][j-2];
        			if(p[j - 1] == s[i] || p[j - 1]=='.'){
        				dp[i][j] |= dp[i-1][j]; 
        			}
        		}
        	}
        }
        return dp[s.size() - 1][p.size() - 1];
    }

};
int main(){
	string s, p ;
	cin>>s>>p;
	Solution ob;
	printf("%d\n",ob.isMatch(s,p));
}
