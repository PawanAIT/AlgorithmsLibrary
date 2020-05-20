#include "bits/stdc++.h"
using namespace std;
main()
{    std::map<string,int> key;
    char str[33];int t,x;
    for(scanf("%d",&t);t--;scanf("%s",str),x=0,(x=++key[str])==1?    printf("OK\n"):printf("%s%d\n",str,x-1));        
}
