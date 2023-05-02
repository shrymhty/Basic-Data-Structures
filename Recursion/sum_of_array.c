#include<stdio.h>
#include<stdbool.h>

int sum(int a[],int n)
{
    if(n==0)
    {
        return 0;
    }
    int d=a[0];
    return sum(a+1,n-1)+d;
}

int main()
{
    int arr[]={1,2,3,4,5};
    printf("%d",sum(arr,5));
    return 0;
}