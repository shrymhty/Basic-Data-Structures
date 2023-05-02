#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,*list;
    printf("Enter the number of values in the array: ");
    scanf("%d",&n);
    list=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of element[%d]: ",i);
        scanf("%d",&list[i]);
    }
    printf("\nThe user defined array: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",list[i]);
    }
}