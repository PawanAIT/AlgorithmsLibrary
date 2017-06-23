#include <stdio.h>
long long xGCD(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    long long x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    //printf("%d %d %d %d %d %d\n",a,b,x,y,x1,y1);
    return gcd;
}


int main()
{
    long long x,a,b,y;
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long gcd;
        scanf("%lld%lld",&a,&b);
        gcd=xGCD(a,b,x,y);
        if (gcd!=1)
        {
            printf("-1\n");
        }
        else
            if(x<=0)
                printf("%lld\n",x+b);
            else
                printf("%lld\n",x);
    }
    

}
