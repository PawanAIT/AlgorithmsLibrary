 #include "bits/stdc++.h"
    using namespace std;
    int main(int argc, char const *argv[])
    {
        std::ios::sync_with_stdio(false);
        string A,B,C;
        cin>>A>>B>>C;
        map<char,int>v;
        A.append(B);
        int i, x=A.length();
        if (x!=C.length())
        {
                cout<<"NO";
                return 0;
        }
        for ( i = 0; i<x ; ++i)
        {
            v[A[i]]++;
            v[C[i]]++;
        }

        std::map<char, int>::iterator itr;
        for (itr=v.begin(); itr!=v.end(); ++itr)
        {
            if (((itr->second))%2)
            {
                cout<<"NO";
                return 0;
            }
        }

    cout<<"YES";
    return 0;
    }
