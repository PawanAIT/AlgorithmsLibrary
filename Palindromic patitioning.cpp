#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int N = 1e3;
    int minCut(string s) {
        int palin[N][N];
        int n = s.size();
        memset(palin ,0 , sizeof(palin));
        for(int i = 0 ; i < n ; i++)
            palin[i][i] = 1;
        
        for(int gap = 2 ;gap <= n ;gap++){
            for(int i = 0 ; i < n - gap + 1; i++){
                int j = i + gap - 1;
                if(gap == 2)
                    palin[i][j] = (s[i] == s[j]);
                else if((s[i] == s[j]) && palin[i + 1][j - 1])
                    palin[i][j] = 1;
            }
        }
        int ans[N];
        memset(ans , 0 , sizeof(ans));
        for(int i = 0 ; i < n ; i++){
           if(palin[0][i])
               ans[i] = 0;
            else{
                ans[i] = INT_MAX;
                for(int j = 0 ;j < i; j++){
                    if(ans[i] > ans[j] + 1 and palin[j + 1][i])
                        ans[i] = ans[j] + 1;
                }
            }
        }
        return ans[n - 1];
    }
};

int main() {
    int t ;
    scanf("%d" , &t);
    while(t--){
        string ss;
        cin >> ss;
        Solution obj;
        cout << obj.minCut(ss) << endl;
    }
    return 0;
}
