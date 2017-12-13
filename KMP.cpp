#include <bits/stdc++.h>
using namespace std;
int main(){
    string text , pat;
    cin >> text >> pat;
    vector<int> Lps(pat.size() + 1 , 0);
    int n = text.size();
    int m = pat.size();
    int i = 1 , j = 0;
    while(i < m){
      if(pat[i] == pat[j])
          Lps[i] = j + 1 ,i++ , j++;
      else if (j == 0) i++;
      else j = Lps[j - 1]; 
    }
    i = 0, j = 0;
    while(i < n and j < m){
        if(text[i] == pat[j])
            i++ , j++;
        else if(j == 0)i++;
        else
          j = Lps[j - 1];
    }

    if (j == m){
      cout << "found at " << i - j << " ";
    }
    else
      cout << "not found\n";
}
