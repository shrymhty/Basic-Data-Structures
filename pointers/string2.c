#include <stdio.h>
int main(void)
{
    char a[50];
    printf("Enter your name:\n");
    scanf("%[^\n]",a);
    char *p=a;
    for(int i=1;i<50;i++)
    {
        printf("%c",*(p+i));
    }
    return 0;
}