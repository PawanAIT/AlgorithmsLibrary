#include <iostream>
#include <string.h>
using namespace std;

int main() {
   char  a[100000],b[100000],c[100000];//in online judges you may have very long string 
   
 cin>>a>>b;
    strcpy(c,a);
    
    cout<<strlen(a)<<' '<<strlen(b)<<endl;
    cout<<strcat(a,b)<<endl;
    cout<<b[0]<<c+1<<' '<<a[0]<<b+1;
  
    return 0;
}
