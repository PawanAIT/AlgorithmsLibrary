#include "iostream"
#include "string.h"
using namespace std;
int main(int argc, char const *argv[])
{
    int  t;
    cin>>t;
    while(t--)
    {
        char str[1000];
        cin>>str;
        if(strlen(str)>10)
        {
            cout<<str[0]<<strlen(str)-2<<str[strlen(str)-1]<<endl;
        }
        else
            cout<<str<<endl;  
    }
    return 0;
}
