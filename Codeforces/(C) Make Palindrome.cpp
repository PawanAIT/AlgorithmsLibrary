#include "bits/stdc++.h"
#define ll __int64
using namespace std;

int main()
{    std::ios::sync_with_stdio(false);
    string ss;
    int arr[26]={0};
    cin>>ss;
    for (int i = 0; i < ss.length(); ++i)
    {
        arr[ss[i]-'a']++;
    }

   int i=0, j=26;
    while(i<j)
    {
        while(arr[i]%2==0)i++;
        while(arr[j]%2==0)j--;
        arr[i]++,arr[j]--;
    }
    char ch='-';
    for (int i = 0; i < 26; ++i)
    {
        if (arr[i]%2)
        {
           ch=i+'a';
           break;
        }
    }
    string ss1="";
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < arr[i]/2; ++j)
        {
           ss1.push_back(char(i+'a'));
        }
    }
    cout<<ss1;
    if (ch!='-')
    {
        cout<<ch;
    }
        for (int i = ss1.length()-1; i>=0; i--)
        {
            cout<<ss1[i];
        }
    
    return 0;
}
