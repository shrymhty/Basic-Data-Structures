#include<stdio.h>
#include<stdbool.h>

int result(int arr[],int n)
{
    int i=0;
    while(i+1<n&&arr[i]<arr[i+1])
    {
        i++;
    }
    if(i==0||i==n-1)
    {
        return 0;
    }
    while(i+1<n&&arr[i]>arr[i+1])
    {
        i++;
    }
    if(i==n)
    {
        return 1;
    }
}

int main()
{
    int a[10];
    printf("Enter 10 numbers: ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Result: %d",result(a,10));
    return 0;
}