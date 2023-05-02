#include<stdio.h>

int index(int a[],int n, int num,int i)
{
    if(i==n)
    {
        return -1;
    }
    if(a[i]==num)
    {
        return i;
    }
    return index(a,n,num,i+1);
}

int main()
{
    int arr[]={1,2,3,4,5};
    printf("%d",index(arr,5,3,0));
    return 0;
}