#include <stdio.h>
void series(int);
void series(int n)
{
    if(n>1)
    {
        printf("%d ",n);
        series(n-2);
    }
    else
    {
        return;
    }

}
int main()
{
    int n=10;
    printf("The number series required: ");
    series(n);
    return 0;
}