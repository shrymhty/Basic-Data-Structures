#include<stdio.h>
int main()
{
    int a[6];
    int temp;
    int i;
    printf("Enter the elements of the array:\n ");
    for(i=0;i<6;i++)
    {
        printf("Enter the value of a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    //interchanging the third element with the first element
    int *p1=&a[0];
    int *p2=&a[3];
    for(i=0;i<3;i++)
    {
        temp=*p2;
        *p2=*p1;
        *p1=temp;
        p1=p1+1;
        p2=p2+1;
    }
    int *b=&a[0];
    //printing after interchanged
    printf("The array after getting interchanged: \n");
    for(i=0;i<6;i++)
    {
        printf("%d ",*(b+i));
    }
    return 0;
    
}