#include "bits/stdc++.h"
using namespace std;
const int MAXN = 30;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k;
    cin >> n >> k;
    vector<bitset<MAXN>> bits(n);
    for(auto &x : bits) cin >> x;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int bit_count = (bits[i] ^ bits[j]).count();
            ans = min(ans, bit_count);
        }
    }
    cout << ans;
    return 0;
}
