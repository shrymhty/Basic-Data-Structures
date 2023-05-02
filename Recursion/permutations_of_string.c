#include<stdio.h>

void swap(char a, char b)
{
    char t;
    t=a;
    a=b;
    b=t;
}

void print(char a[],int i)
{
    if(a[0]=='\0')
    {
        printf("%s",a);
        return;
    }
    for(int j=i;a[i]!='\0';j++)
    {
        swap(a[i],a[j]);
        print(a,i+1);
        swap(a[i],a[j]);
    }
}

int main()
{
    char arr[]="abc";
    print(arr,0);
    return 0;
}