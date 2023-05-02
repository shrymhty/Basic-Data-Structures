#include <stdio.h>
int main()
{
    char a[10];
    char *b=a;
    int len;
    int i;
    printf("Enter string: ");
    scanf("%s",a);
    for(i=0;i<10;i++)
    {
        if(a[i])
        {
            len=len+1;
        }
    }
    for(i=0;i<len;i++)
    {
        *(b+i)=(int)(a[i]);
    }
    printf("The array with the ascii codes: \n");
    for(i=0;i<len;i++)
    {
        printf("%d ",*(b+i));
    }
    printf("The characters wih even ascii code: \n");
    for(i=0;i<len;i++)
    {
        if(*(b+i)%2==0)
        {
            printf("%d ",*(b+i));
        }
    }
}