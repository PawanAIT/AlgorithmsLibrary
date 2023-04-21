#include "bits/stdc++.h"
#pragma GCC target("popcnt") //important for POPCOUNT instruction.
using namespace std;
const int MAXN = 3000 + 5;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<bitset<MAXN>> bits(n);
    for(auto &x : bits) cin >> x;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int bit_count = (bits[i] & bits[j]).count();
            ans += 1LL * bit_count * (bit_count - 1);
        }
    }
    cout << ans / 2;
    return 0;
}
