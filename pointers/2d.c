#include <stdio.h>
int main()
{
    int a[3][4];
    printf("Enter the elements of the 3 x 4 matrix: \n");
    int i;
    int j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Enter the value of a[%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("The array diisplayed in forward order using pointers: \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
    printf("The array displayed in backward direction using pointers: \n");
    for(i=2;i>=0;i--)
    {
        for(j=3;j>=0;j--)
        {
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }

}