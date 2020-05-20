#include "iostream"
#include "math.h"
using namespace std;
int main()
{
    long  double  a,b,c;
    unsigned long long int q; 
    cin>>a>>b>>c;
    q=ceil(a/c)*ceil(b/c);
    cout<<q;
    return 0;
}
