#include "bits/stdc++.h"
using namespace std;
int main() {
    int n, tx;
    cin >> n >> tx;
    vector<int> a(n / 2), b(n - n / 2);
    for(int i = 0; i < n / 2; i++){
        cin >> a[i];
    }
    for(int i = n / 2; i < n; i++){
        cin >> b[i - n / 2];
    }
    using LL = long long;
    LL ans = 0;
    unordered_map<LL,  int> mp;
    function<void(int, int, LL, bool)> dfs = [&](int idx, int n, LL sum, bool _left){
        if(idx == n){
            if(_left) mp[sum]++;
            else if(mp.count(tx - sum)) ans += mp[tx - sum];
            return;
        }
        dfs(idx + 1, n, sum, _left);
        dfs(idx + 1, n, sum + (_left ? a[idx] : b[idx]), _left);
    };
    dfs(0, a.size(), 0, true);
    dfs(0, b.size(), 0, false);
    cout << ans;
    return 0;
}
