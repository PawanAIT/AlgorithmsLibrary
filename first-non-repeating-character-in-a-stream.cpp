//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0/?ref=self
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
    vector<list<char>::iterator> has(26);
    int Hash[26] = { 0 };
    list<char> L;
    char ch;
    int n ;
    cin >> n;
    while(n--){ // read until end of file .
        cin >> ch;
      if(Hash[ch - 'a']){
        if(has[ch - 'a'] != L.end()){
          L.erase(has[ch - 'a']);
        }
        has[ch - 'a'] = L.end();
      }else{
          Hash[ch - 'a'] = 1;
          has[ch - 'a'] = L.insert(L.end(), ch);
      }
      if(L.begin() == L.end()){
          cout << -1 << " ";
      }
      else{
          cout << *L.begin() << " ";
      }
    }
    cout << endl;
}
} 
