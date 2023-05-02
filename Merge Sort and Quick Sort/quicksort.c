#include<stdio.h>


int partition(int a[], int s, int e)
{
    int i,j;
    i=s;
    int pivot=a[e];
    for(j=s;j<=e-1;j++)
    {
        if(a[j]<pivot)
        {
            int t;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
        }
    }
    int t;
    t=a[i];
    a[i]=pivot;
    pivot=t;
    return i;
}
void sort(int a[], int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int p=partition(a,s,e);
    sort(a,s,p);
    sort(a,p+1,e);


}
int main()
{
    int arr[]={5,1,7,2,9,3};
    sort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}