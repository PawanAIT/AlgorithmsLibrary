class Solution {
    int N;
public:
    int minSteps(int n) {
        if(n == 1)
            return 0;
        N = n;
        return 1 + go(1, 1);
    }
    
    int go(int n, int lastcopied){
        if(n > N){
            return INT_MAX/10;
        }
        if(n == N){
            return 0;
        }
        
        // paste ?
        // copy ?
        int l = 1 + go(n + lastcopied, lastcopied);
        int r = 2 + go(n + n , n); // copy + paste.
        
        return min(l , r);
    }
};