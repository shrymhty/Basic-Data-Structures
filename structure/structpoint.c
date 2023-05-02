#include<stdio.h>
struct element
{
    int num;
}s[3];
int main()
{
    int i;
    struct element *ptr=NULL;
    ptr=s;
    printf("Enter three numbers: \n");
    for(i=0;i<3;i++)
    {
        printf("Enter number %d: ",i+1);
        scanf("%d",&s[i].num);
    }
    //printing using pointers
    printf("The numbers are: \n");
    for(i=0;i<3;i++)
    {
        printf("%d\n",ptr->num);
        ptr++;
    }
    return 0;
}