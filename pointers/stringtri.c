#include<stdio.h>
void stringpatt(char s[10])
{ 
    char t[10]={0};
    int i;
    for(i=0;i<10;i++) //length
    {
        if(s[i]=='\0')
        {
            break;
        }
        else
        {
            continue;
        }
    }
    for(int l=0;l<i;l++)
    {
        t[l]=s[l];
    }
    char *a;
    a=&t[0];
    int n,j,k;
    n=i;
    char *b=a;
    for(k=n;k>=1;k--)
    {
        for(j=0;j<k;j++)
        {
            printf("%c",*(b+j));
        }
        printf("\n");
        a=a+1;
        b=a;
    }
}
int main()
{
    char str[10]={0};
    printf("Enter a word:\n");
    scanf("%s",str);
    stringpatt(str);
    return 0;
}
/*#include<stdio.h>
int main()
{
    char str[5];
    printf("Enter a string of 5 characters\n");
    scanf("%s",str);
    char *b=str;
    int i;
    int j;
    for(i=4;i>=0;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%c ",*(b+j));
        }
        printf("\n");
        b++;
    }
}*/
//code with correct logic but errors