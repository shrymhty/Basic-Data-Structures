#include <stdio.h>
int main()
{
   /* int i[4],j[4];
    for(int k=0;k<=4;k++)
    {
        i[k]=10;
        j[k]=11;
    }
    printf("%d",i[0]); //j[0] gets overwritten by i[4]*/
    int i=300;
    char *c;
    c=(char*)&i;
    *(c+1)=2;
    printf("%d",i);

} 