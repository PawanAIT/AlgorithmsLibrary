#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char arr[10000];int a[26]={0},flag=0,i;
    scanf("%[^\n]s",arr);
    for(i=0;i<strlen(arr);i++)
       
       {
       if(arr[i]<97&&arr[i]>=65)
       arr[i]=arr[i]+32;
        a[arr[i]-'a']++;
    }
    for(i=0;i<26;i++)
       if(a[i]==0)
        {
        printf("not pangram");
        flag=1;
        break;
    }
    if(flag!=1)
        {
        printf("pangram");
    }
    return 0;
}
