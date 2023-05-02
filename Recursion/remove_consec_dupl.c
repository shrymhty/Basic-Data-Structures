#include<stdio.h>

void remove_dup(char a[])
{
    if(a[0]=='\0')
    {
        return;
    }
    if(a[0]!=a[1])
    {
        remove_dup(a+1);
    }
    else 
    {
        for(int i=0;a[i]!='\0';i++)
        {
            a[i]=a[i+1];
        }
        remove_dup(a+1);
    }
}

int main()
{
    char arr[]="aabbbch";
    remove_dup(arr);
    printf("%s",arr);
    return 0;
}