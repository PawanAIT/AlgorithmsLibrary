#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char str[10];
    int a,rem,i;
    char b; 
    scanf("%s",str);
    if(str[8]=='P')
        {
        	a=(int)str[0]-48; //printf("%d\n",a);
        	b=(int)str[1]-48; //printf("%d\n",b);
    		a=10*a+b+12;
        	i=1;
            if(a<24)
                {
        	str[1]=char(a%10+48);
            str[0]=char(a/10+48);
            }
			str[8]='\0';

		}
    else
        {
        if(str[0]=='1'&&str[1]=='2')
        {str[0]='0';
        str[1]='0';
        }
        str[8]='\0';
    }
    printf("%s",str);
	return 0;
}
