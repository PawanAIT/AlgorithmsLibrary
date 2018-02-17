#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
char s[N] ,a[N];
int Rank[N] , suff[N] , temp[N] , Lcp[N];
int n , gap;
long long h[30];
bool cmp(int i , int j){
    if(Rank[i] != Rank[j])
        return Rank[i] < Rank[j];
    i += gap;
    j += gap;
    if(i < n && j < n)
        return Rank[i] < Rank[j];
    else
        return i > j;
}
void buildSA(){
    for(int i = 0 ; i < n ; i++){
        suff[i] = i , Rank[i] = s[i];
    }
    for(gap = 1 ; ; gap <<=1){
        sort(suff , suff + n , cmp);
 
        for(int i = 0 ; i < n  ; i++)
            temp[i + 1] = temp[i] + cmp(suff[i] , suff[i + 1]);
        
        for(int i = 0 ; i < n ; i++){
            Rank[suff[i]] = temp[i];
        }
        if(temp[n - 1] == n - 1)
            break;
    }
}
void buildLcp(){
    int k = 0;
    for(int i = 0 ; i < n ; i++ ){

        if(Rank[i] == n - 1){
            k = 0;
            continue; 
        }
        int j = suff[Rank[i] + 1];
        while(i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
        Lcp[Rank[i]] = k;
        if( k ) k--;   
    }
}
int main(){
    scanf("%s" , s);
    n = strlen(s);
    buildSA();
    buildLcp();
 
    int ans = 0;
    for (int i = 0; i < n ; ++i){
       h[s[suff[i]] - 'a'] += (n - suff[i]) - Lcp[i];
    }
    for (int i = 0; i < 26; ++i){
        printf("%lld%c", h[i] , " \n"[i == 25]);
    }
    return 0;
} 
