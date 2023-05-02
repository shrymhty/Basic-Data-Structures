#include<stdio.h>

void insertion(int a[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=a[i];
        while(a[j]>key&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array to be sorted: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertion(arr,n);
    printf("The sorted array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}