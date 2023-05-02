#include <stdio.h>
void digitrev(int);
void digitrev(int num)
{
    int n;
    if(num)
    {
        n=num%10;
        printf("%d ",n);
        num=num/10;
        digitrev(num);
    }
    else
    {
        return;
    }
}
int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d",&num);
    printf("Digits in reverse order: ");
    digitrev(num);
    return 0;
}