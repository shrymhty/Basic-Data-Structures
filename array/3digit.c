#include<stdio.h>
int main()
{
    int c=0;
    int k=0;
    int arr[10];
    printf("Enter elements: \n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<10;i++)
    {
        while(arr[i]!=0)
        {
            arr[i]=arr[i]/10;
            c++;
        }
        if(c==3)
        {
            k++;
        }
        c=0;  
    }
    printf("%d",k);
    if(k==10)
    {
        printf("success");
    }
    return 0;
}