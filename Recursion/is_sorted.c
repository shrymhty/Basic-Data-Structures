#include<stdio.h>
#include<stdbool.h>

bool isSorted(int a[],int n)
{
    if(n==0|n==1)
    {
        return true;
    }
    if(a[n-2]>a[n-1])
    {
        return false;
    }
    return isSorted(a+1,n-1);
}

int main()
{
    int arr[]={1,2,3,4};
    if(isSorted(arr,4))
    {
        printf("true");
    }
    else 
    {
        printf("false");
    }
    return 0;
}