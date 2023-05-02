    #include <stdio.h>
     
    int main()
    {
       int a, b, *p, *q, temp;
       printf("Enter the value of first integer:");
       scanf("%d",&a);
       printf("Enter the value of the second integer: ");
       scanf("%d",&b);
       printf("Before Swapping:\nA\tB\n%d\t%d",a,b);
       p=&a;
       q=&b;
       temp=*q;
       *q=*p;
       *p=temp;
       printf("\nAfter Swapping:\nA\tB\n%d\t%d",a,b);
       return 0;
    }
     

