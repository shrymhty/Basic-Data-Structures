#include<stdio.h>
#include<string.h>

void subsequences(char a[], char out[])
{
    if(strlen(a)==0)
    {
        printf("%s\n",out);
        return;
    }
    subsequences(a+1,out);
    subsequences(a+1,out+a[0]);
    
}

int main()
{
    char arr[]="abc";
    char out[]="";
    subsequences(arr,out);
    return 0;
}