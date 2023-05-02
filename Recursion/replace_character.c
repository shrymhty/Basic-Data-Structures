#include<stdio.h>

void replace(char a[], char ch, char dest_ch)
{
    if(a[0]=='\0')
    {
        return;
    }
    if(a[0]==ch)
    {
        a[0]=dest_ch;
    }
    replace(a+1,ch,dest_ch);
}

int main()
{
    char arr[]="abcd";
    replace(arr,'b','r');
    printf("%s",arr);
    return 0;
}