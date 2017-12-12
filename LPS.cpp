// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
      string ss;
      cin >> ss;
      vector<int> f(ss.size() + 1 , 0);
      int n = ss.size();
      int i = 1 , j = 0;
      while(i < n){
        if(ss[i] == ss[j])
            f[i] = j + 1 ,i++ , j++;
        else if (j == 0) i++;
        else j = f[j - 1]; 
      }
      cout << f[n - 1] << endl;
  }
}
