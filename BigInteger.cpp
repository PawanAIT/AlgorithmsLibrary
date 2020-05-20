const int maxlength=2000;

class BigInt
{
    public:
        int oper,length,a[maxlength],sqrtL;
        BigInt(int=0);
        ~BigInt();
        int max(int a,int b);
        void check();
        void operator=(BigInt m);
        void operator=(int m);
        void operator=(char *s);
        //bool operator<(BigInt m);
        friend bool operator<(BigInt a,BigInt m);
        bool operator<=(BigInt m);
        bool operator>(BigInt m);
        bool operator>=(BigInt m);
        bool operator==(BigInt m);
        bool operator!=(BigInt m);
        BigInt operator-();
        BigInt operator+(BigInt m);
        void operator+=(BigInt m);
        BigInt operator-(BigInt m);
        void operator-=(BigInt m);
        BigInt operator*(BigInt m);
        BigInt operator*(int m);
        void operator*=(BigInt m);
        void operator*=(int m);
        BigInt operator/(BigInt m);
        BigInt operator/(int m);
        void operator/=(BigInt m);
        void operator/=(int m);
        BigInt operator%(BigInt m);
        BigInt operator%(int m);
        void operator%=(BigInt m);
        void operator%=(int m);
};

BigInt abs(BigInt m);
bool read(BigInt &m);
void write(BigInt m);
void swrite(char *s,BigInt m);
void writeln(BigInt m);
BigInt sqr(BigInt m);
BigInt sqrt(BigInt m);
BigInt gcd(BigInt a,BigInt b);
BigInt lcm(BigInt a,BigInt b);

int BigInt::max(int a,int b)
{
    return (a>b)?a:b;
}
BigInt::BigInt(int v)
{
    (*this)=v;
    this->check();
}
BigInt::~BigInt()
{
}
void BigInt::check()
{
    for (;length>0 && a[length]==0;length--);
    if (length==0)
        oper=1;
}
void BigInt::operator=(BigInt m)
{
    oper=m.oper;
    length=m.length;
    memcpy(a,m.a,maxlength*sizeof(int));
    this->check();
}
void BigInt::operator=(int m)
{
    oper=(m>0)?1:-1;
    m=abs(m);
    memset(a,0,maxlength*sizeof(int));
    for (length=0;m>0;m=m/10000)
        a[++length]=m%10000;
    this->check();
}
void BigInt::operator=(char *s)
{
    int i,L;
    (*this)=0;
    if (s[0]=='-' || s[0]=='+')
    {
        if (s[0]=='-')
            oper=-1;
        L=strlen(s);
        for (i=0;i<L;i++)
            s[i]=s[i+1];
    }
    L=strlen(s);
    //printf("length is %d\n\n",L);
    sqrtL=L;
    length=(L+3)/4;
    for (i=0;i<L;i++)
        a[(L-i+3)/4]=a[(L-i+3)/4]*10+(s[i]-48);
    this->check();
}
bool operator<(BigInt a,BigInt m)
{
    if (a.oper!=m.oper)
        return a.oper<m.oper;
    if (a.length!=m.length)
        return a.oper*a.length<m.length*m.oper;
    for (int i=a.length;i>=1;i--)
        if (a.a[i]!=m.a[i])
            return a.a[i]*a.oper<m.a[i]*m.oper;
    return false;
}
bool BigInt::operator<=(BigInt m)
{
    return !(m<(*this));
}
bool BigInt::operator>(BigInt m)
{
    return m<(*this);
}
bool BigInt::operator>=(BigInt m)
{
    return !((*this)<m);
}
bool BigInt::operator==(BigInt m)
{
    return (!((*this)<m)) && (!(m<(*this)));
}
bool BigInt::operator!=(BigInt m)
{
    return ((*this)<m) || (m<(*this));
}
BigInt BigInt::operator-()
{
    BigInt c=(*this);
    c.oper=-c.oper;
    c.check();
    return c;
}
BigInt abs(BigInt m)
{
    BigInt c=m;
    c.oper=abs(c.oper);
    c.check();
    return c;
}
BigInt BigInt::operator+(BigInt m)
{
    if (m.length==0)
        return (*this);
    if (length==0)
        return m;
    if (oper==m.oper)
    {
        BigInt c;
        c.oper=oper;
        c.length=max(length,m.length)+1;
        for (int i=1,temp=0;i<=c.length;i++)
            c.a[i]=(temp=(temp/10000+a[i]+m.a[i]))%10000;
        c.check();
        return c;
    }
    return (*this)-(-m);
}
BigInt BigInt::operator-(BigInt m)
{
    if (m.length==0)
        return (*this);
    if (length==0)
        return (-m);
    if (oper==m.oper)
    {
        BigInt c;
        if (abs(*this)>=abs(m))
        {
            c.oper=oper;
            c.length=length;
            for (int i=1,temp=0;i<=length;i++)
                c.a[i]=((temp=(-int(temp<0)+a[i]-m.a[i]))+10000)%10000;
            c.check();
            return c;
        }
        return -(m-(*this));
    }
    return (*this)+(-m);
}
bool read(BigInt &m)
{
    char s[maxlength*4+10];
    if (scanf("%s",s)==-1)
        return false;
    //printf("string is\n%s\n\n",s);
    for (int i=0;s[i];i++)
        if (!(s[i]>='0' && s[i]<='9' || (s[i]=='+' || s[i]=='-') && i==0))
            return false;
    m=s;
    return true;
}
void swrite(char *s,BigInt m)
{
    int L=0;
    if (m.oper==-1)
        s[L++]='-';
    sprintf(s+L,"%d",m.a[m.length]);
    for (;s[L]!=0;L++);
    for (int i=m.length-1;i>=1;i--)
    {
        sprintf(s+L,"%04d",m.a[i]);
        L+=4;
    }
    s[L]=0;
}
void write(BigInt m)
{
    //printf("m=%d\n",m.length);
    if (m.oper==-1)
        printf("-");
    printf("%d",m.a[m.length]);
    for (int i=m.length-1;i>=1;i--)
        printf("%04d",m.a[i]);
}
void writeln(BigInt m)
{
    write(m);
    printf("\n");
}
BigInt BigInt::operator*(BigInt m)
{
    BigInt c;
    c.oper=oper*m.oper;
    c.length=length+m.length;
    for (int i=1;i<=m.length;i++)
    {
        int number=m.a[i],j,temp=0;
        for (j=1;j<=length;j++)
            c.a[i+j-1]+=number*a[j];
        if (i%10==0 || i==m.length)
            for (j=1;j<=c.length;j++)
                c.a[j]=(temp=(temp/10000)+c.a[j])%10000;
    }
    c.check();
    return c;
}
BigInt BigInt::operator*(int m)
{
    if (m<0)
        return -((*this)*(-m));
    if (m>100000)
        return (*this)*BigInt(m);
    BigInt c;
    c.length=length+2;
    c.oper=oper;
    int t=0;
    for (int i=1;i<=c.length;i++)
        c.a[i]=(t=(t/10000+a[i]*m))%10000;
    c.check();
    return c;
}
BigInt BigInt::operator/(BigInt m)
{
    if (m.length==0)
    {
        printf("Division by zero.\n");
        exit(0);
    }
    if (abs(*this)<abs(m))
        return 0;
    BigInt c,left;
    c.oper=oper/m.oper;
    m.oper=1;
    c.length=length-m.length+1;
    left.length=m.length-1;
    memcpy(left.a+1,a+length-left.length+1,left.length*sizeof(int));
    for (int i=c.length;i>=1;i--)
    {
        left=left*10000+a[i];
        int head=0,tail=10000,mid;
        while (head+1<tail)
        {
            mid=(head+tail)/2;
            if (m*mid<=left)
                head=mid;
            else
                tail=mid;
        }
        c.a[i]=head;
        left-=m*head;
    }
    c.check();
    return c;
}
BigInt BigInt::operator/(int m)
{
    if (m<0)
        return -((*this)/(-m));
    if (m>100000)
        return (*this)/BigInt(m);
    BigInt c;
    c.oper=oper;
    c.length=length;
    int t=0;
    for (int i=c.length;i>=1;i--)
        c.a[i]=(t=(t%m*10000+a[i]))/m;
    c.check();
    return c;
}
BigInt BigInt::operator %(BigInt m)
{
    return (*this)-((*this)/m)*m;
}
BigInt BigInt::operator%(int m)
{
    if (m<0)
        return -((*this)%(-m));
    if (m>100000)
        return (*this)%BigInt(m);
    int t=0;
    for (int i=length;i>=1;i--)
        t=(t*10000+a[i])%m;
    return t;
}
BigInt sqr(BigInt m)
{
    return m*m;
}
BigInt sqrt(BigInt m)
{
    if (m.oper<0 || m.length==0)
        return 0;
    BigInt c,last,now,templast;
    c.length=(m.length+1)/2;
    c.a[c.length]=int(sqrt((double)m.a[c.length*2]*10000+m.a[c.length*2-1])+1e-6);
    templast.length=c.length*2;
    templast.a[c.length*2-1]=(c.a[c.length]*c.a[c.length])%10000;
    templast.a[c.length*2]=(c.a[c.length]*c.a[c.length])/10000;
    templast.check();
    for (int i=c.length-1;i>=1;i--)
    {
        last=templast;
        int head=0,tail=10000,mid,j,temp;
        while (head+1<tail)
        {
            mid=(head+tail)/2;
            now=last;
            now.a[2*i-1]+=mid*mid;
            for (j=i+1;j<=c.length;j++)
                now.a[i+j-1]+=mid*c.a[j]*2;
            now.length++;
            for (j=2*i-1,temp=0;j<=now.length;j++)
                now.a[j]=(temp=(temp/10000+now.a[j]))%10000;
            now.check();
            if (now<=m)
            {
                templast=now;
                head=mid;
            }
            else
                tail=mid;
        }
        c.a[i]=head;
    }
    c.check();
    return c;
}
BigInt gcd(BigInt a,BigInt b)
{
    return (b==0)?a:gcd(b,a%b);
}
BigInt lcm(BigInt a,BigInt b)
{
    return a*b/gcd(a,b);
}
void BigInt::operator+=(BigInt m)
{
    (*this)=(*this)+m;
}
void BigInt::operator-=(BigInt m)
{
    (*this)=(*this)-m;
}
void BigInt::operator*=(BigInt m)
{
    (*this)=(*this)*m;
}
void BigInt::operator/=(BigInt m)
{
    (*this)=(*this)/m;
}
void BigInt::operator%=(BigInt m)
{
    (*this)=(*this)%m;
}
void BigInt::operator*=(int m)
{
    (*this)=(*this)*m;
}
void BigInt::operator/=(int m)
{
    (*this)=(*this)/m;
}
void BigInt::operator%=(int m)
{
    (*this)=(*this)%m;
}