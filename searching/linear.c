#include<stdio.h>

void search(int arr[],int key,int n)
{
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        {
            pos=i;
        }
    }
    if(pos==-1)
    {
        printf("Not found");
    }
    else 
    {
        printf("found at %d",pos);
    }
}

int main()
{
    printf("Enter the number of elements: ");
    int n;
    int k;
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the value to be searched: ");
    scanf("%d",&k);
    search(a,k,n);
    return 0;
}