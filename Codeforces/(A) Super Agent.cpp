#include "iostream"
#include "math.h"
using namespace std;
int main()
{
    char a[3][3];
    int count=0,count2=0,count4=0,count3=0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j< 3; ++j)
        {
            cin>>a[i][j];
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if(a[0][i]=='.')
            count++;
        if(a[2][i]=='.')
            count2++;
        if (a[i][0]=='.')
        {
            count3++;
        }
        if (a[i][2]=='.')
        {
            count4++;
        }
    }
if(count==count2&&count3==count4)
    cout<<"YES";
else
    cout<<"NO";
}
