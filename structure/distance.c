#include<stdio.h>
int display(int a[],int num, int x, int y)
{
    int index1,index2;
    int dist;
    for(int j=0;j<num;j++)
    {
        if(a[j]==x)
        {
            index1=j;
            break;
        }
    }
    for(int i=0;i<num;i++)
    {
        if(a[i]==y)
        {
            index2=i;
            break;
        }
    }
    dist=index2-index1;
    printf("The minimum distance %d",dist);
    return 0;
}
int main()
{
    int n;
    int a,b;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    int i;
    printf("Enter the elements: \n");
    for(i=0;i<n;i++)
    {
        printf("Enter arr[%d]",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    display(arr,n,a,b);
}
