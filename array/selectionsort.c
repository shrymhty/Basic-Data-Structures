#include<stdio.h>

int main()
{
    int i;
    int j;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: \n");
    for(i=0;i<n;i++)
    {
        printf("Element[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    int temp;
    int min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;   
            }
            if(min!=i)
            {
                temp=arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
        }
    }
    printf("\nThe sorted array: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}