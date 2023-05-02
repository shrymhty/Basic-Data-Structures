#include <stdio.h>
int main()
{
    int a;
    int *b;
    printf("Enter a: ");
    scanf("%d",&a);
    b=&a;
    printf("The pointer address: %p",b);
    printf("\nThe value stored in b pointer: %d",*b);
}