#include "bits/stdc++.h"
    using namespace std;
    int main(int argc, char const *argv[])
    {
        std::ios::sync_with_stdio(false);
        string A,B;
        cin>>A>>B;
        A.append(B);
        int i, x=A.length();
        
        for ( i = 0; i<x/2 ; ++i)
        {
            if(A[i]!=A[x-1-i])break;
        }

        if (i==x/2)
        {
            cout<<"YES";
        }

        else
            cout<<"NO";
        return 0;
    }
