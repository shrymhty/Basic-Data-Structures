#include <stdio.h>
int main()
{
    int x[2]={30,31},*y,*z;
    y=x;
    z=y;
    *++y=*z++;
    (*z)++;
    printf("%d %d",x[0],x[1]);
    return 0;
}