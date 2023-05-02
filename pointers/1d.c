#include <stdio.h>
int main()
{
    int a[5];
    int *b=&a[0];
    int i;
    for(i=0;i<5;i++)
    {
        printf("Enter the value of a[%d]",i);
        scanf("%d",b+i);
    }
    //printing the array in the inputted order
    printf("The array displayed using pointers: \n");
    for(i=0;i<5;i++)
    {
        printf("%d ",*(b+i));
    }
    return 0;
}