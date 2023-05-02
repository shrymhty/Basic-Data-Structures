#include <stdio.h>
#include <limits.h>
int main()
{
    int arr[5];
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    int largest=INT_MIN;
    int smallest=INT_MAX;
    for(i=0;i<5;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
        if(arr[i]<smallest)
        {
            smallest=arr[i];
        }
    }
    printf("\nThe largest number is %d\nThe smallest number is %d",largest,smallest);
}