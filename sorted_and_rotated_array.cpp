#include <bits/stdc++.h>
using namespace std;
int main(){
   int  n, key;
   cin >> n >> key;
   vector<int> arr(n);
   for(auto &temp : arr)
        cin >> temp;
    int low = 0 , high = n - 1;
    bool ok = false;
    while(low <= high){
        int mid = low + high >> 1;
        if(arr[mid] == key){
            cout << "Found at " << mid;
            ok = true;
            break;
        }
        if(arr[low] <= arr[mid]){
            if(key >= arr[low] and key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(arr[mid] <= arr[high]){
            if(key <= arr[high] and key > arr[mid])
                low = mid + 1;
            else 
                high = mid - 1;
        }
    }
    if(!ok)
        cout << "Not Found\n";
}
