#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
int l,ext,i;
char str[100000];
scanf("%d",&l);

scanf("%s",str);

scanf("%d",&ext);
ext=ext%26;

for(i=0;i<l;i++)
    {  
if(str[i]>=65 && str[i]<=90)
    {if(str[i]+ext>90)
       str[i]=str[i]+ext-26;
        else
            str[i]+=ext;
    }
else if(str[i]>=97 && str[i]<=122)
    {
    if(str[i]+ext>122)
        str[i]=str[i]+ext-26;
    else
        str[i]=str[i]+ext;
        
}
    
    }
for(i=0;i<l;i++)
{
	printf("%c",str[i]);
}

    
    return 0;
}




