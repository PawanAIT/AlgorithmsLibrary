#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n , key;
        cin >> n >> key;   
        vector<int> v(n);
        for(auto &temp : v)
            cin >> temp;
        int low = 0 , high = n - 1;
        while(low <= high){
            int mid = low + high >> 1;
            if(key <= v[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        int start = low ;
        low = 0 , high = n - 1;
        while(low <= high){
            int mid = low + high >> 1;
            if(key >= v[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        int end = low;
        if(end - start)
            cout << end - start << endl;
        else
            cout << - 1 << endl;
    }
}
