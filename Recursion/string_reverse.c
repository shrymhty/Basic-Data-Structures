#include<stdio.h>

void print(char a[])
{
    if(a[0]=='\0'){
        return;
    }
    printf("%c",a[0]);
    print(a+1);
}

void rev(char a[])
{
    if(a[0]=='\0')
    {
        return;
    }
    rev(a+1);
    printf("%c",a[0]);
}

int main()
{
    char arr[]="abc";
    print(arr);
    printf("\n");
    rev(arr);
    return 0;
}