#include <stdio.h>
struct date
{
    int dd;
    int mm;
    int yyyy;
}s[3];
int main()
{
    for(int i=0;i<2;i++)
    {
        printf("Enter day %d: ",i+1);
        scanf("%d",&s[i].dd);
        printf("Enter month %d: ",i+1);
        scanf("%d",&s[i].mm);
        printf("Enter year %d: ",i+1);
        scanf("%d",&s[i].yyyy);
    }
    if(s[1].yyyy==s[0].yyyy)
    {
        if(s[1].mm<s[0].mm)
        {
            printf("%d/%d/%d is earlier",s[1].dd,s[1].mm,s[1].yyyy);
        }
        else if(s[1].mm>s[0].mm)
        {
            printf("%d/%d/%d is earlier",s[0].dd,s[0].mm,s[0].yyyy);
        }
        else
        {
            if(s[0].dd>s[1].dd)
            {
                printf("%d/%d/%d is earlier",s[1].dd,s[1].mm,s[1].yyyy);
            }
            else if(s[0].dd<s[1].dd)
            {
                printf("%d/%d/%d is earlier",s[0].dd,s[0].mm,s[0].yyyy);
            }
            else 
            {
                printf("Same dates");
            }
        }
    }
    else if(s[0].yyyy<s[1].yyyy)
    {
        printf("%d/%d/%d is earlier",s[0].dd,s[0].mm,s[0].yyyy);
    }
    else
    {
        printf("%d/%d/%d is earlier",s[1].dd,s[1].mm,s[1].yyyy);
    }
}