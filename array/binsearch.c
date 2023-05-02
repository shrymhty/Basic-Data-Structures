#include<stdio.h>

int main()
{
    int arr[10];
    int num;
    int result=-1;
    printf("Enter elements: \n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    int beg=0;
    int end=9;
    int mid;
    printf("Enter the number to be searched: ");
    scanf("%d",&num);
    while(beg<=end)
    {
        mid=(end+beg)/2;
        if(arr[mid]<=num)
        {
            beg=mid+1;
            result=mid;
        }
        else
        {
            end=mid-1;
        }
    }
    printf("The location of %d is %d: ",num,result);
    return 0;
}