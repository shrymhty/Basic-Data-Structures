#include<stdio.h>

int binary(int arr[], int n, int key)
{
    int left=0;
    int right=n-1;
    int mid=(left+right)/2;

    do
    {
        mid=(left+right)/2;
        if(key<arr[mid])
        {
            right=mid-1;
        }
        else if(key>arr[mid])
        {
            left=mid+1;
        }
    } while (key!=arr[mid]&&left<=right);
    return mid;
}

int main()
{
    int arr[6]={1,2,3,4,5,6};
    int num;
    printf("Enter the number to be found: ");
    scanf("%d",&num);
    int q=binary(arr,6,num);
    if(num==arr[q])
    {
        printf("Found");
    }
    else 
    {
        printf("Not found");
    }
}