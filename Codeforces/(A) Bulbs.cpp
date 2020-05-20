#include <bits/stdc++.h>
using namespace std;

int main()
{
   std::ios::sync_with_stdio(0);
   int m,n;
   cin>>m>>n;
   set<int> v;
   while(m--)
   {
       int w,q;
       cin>>w;
       while(w--)
       {
           cin>>q;
           v.insert(q);
       }
   }
   if(v.size()==n)
   cout<<"YES";
   else
   cout<<"NO";
    return 0;
}
