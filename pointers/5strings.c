#include <stdio.h>
int main()
{
    char a[20];
    int i;
    printf("Enter 5 strings of 3 characters :\n");
    for(i=0;i<5;i++)
    {
        printf("Enter the %d string: ",i);
        scanf("%s",a+4*i);
    }
    for(i=0;i<5;i++)
    {
        printf("%s",a+4*i);
    }
}