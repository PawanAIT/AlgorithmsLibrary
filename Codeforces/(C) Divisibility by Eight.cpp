#include "bits/stdc++.h"
using namespace std;


  string NumberToString ( int Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

int main(int argc, char const *argv[])
{
    vector<string> v;
    int flag=1;
    char arr[10]="hello";
    for (int i = 0; i < 1000; i+=8)
    {
        
        string str = NumberToString(i);
            v.push_back(str);
        
    }
    
  
    string t;
   cin>>t;
    std::vector<char> q;
    
        int i,j,k;
        for (i = 0; i < v.size(); ++i)
        {
            k=0;
            q.clear();
            for (j = 0; t[j]; ++j)
            {
                if (t[j]==v[i][k])
                {
                    q.push_back(t[j]);
                    k++;
                }
            }
            if ((v[i].size())==k)
            {
                printf("YES\n");
             for (int i = 0; i < q.size(); ++i)
            {
            printf("%c",q[i]);
            }
            flag=0;
                break;
            }
        }
    
        if(flag)
        printf("NO");
    
    return 0;
}
