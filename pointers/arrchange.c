#include <stdio.h>
int main(void)
{
    int a[5];
    int *b=&a[0];
    //inputting the array using pointers
    printf("Enter the elements of the array: \n");
    for(int i=0;i<5;i++)
    {
        printf("Value of a[%d]: ",i);
        scanf("%d",&*(b+i));
    }
    //printing the inputted array
    printf("The array: \n");
    for(int j=0;j<5;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\nEnter the new value for the third element: ");
    scanf("%d",&*(b+2));
    printf("The new array is: \n");
    for(int k=0;k<5;k++)
    {
        printf("%d ",*(b+k));
    }
    return 0;
}