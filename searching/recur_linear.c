#include<stdio.h>

int recSearch(int arr[],int l, int r, int x)
{
    if(r<l)
    {
        return -1;
    }
    if(arr[l]==x)
    {
        return l;
    }
    return recSearch(arr,l+1,r,x);
}

int main()
{
    int n;
    int k;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d elements: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to be searched: ");
    scanf("%d",&k);
    int pos=recSearch(arr,0,n-1,k);
    if(pos==-1)
    {
        printf("Element %d not found",k);
    }
    else 
    {
        printf("Element %d is found at %d index.",k,pos);
    }

    return 0;
}