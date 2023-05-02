#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr=(int*)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++)
    {
        scanf("%d",&*(ptr+i));
    }
    int *new_ptr=(int*)malloc(sizeof(int)*10);
    new_ptr=ptr;
    for(int i=5;i<10;i++)
    {
        scanf("%d",&*(new_ptr+i));
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",*(new_ptr+i));
    }
    return 0;

}