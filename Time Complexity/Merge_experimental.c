#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int a[],int x[], int y[], int s, int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=e)
    {
        if(x[i]>y[j])
        {
            a[k++]=y[j++];
        }
        else
        {
            a[k++]=x[i++];
        }
    }
    while(i<=mid)
       {
        a[k++] = x[i++];
       }
       while(j<=e)
       {
        a[k++] = y[j++];
       }
}

void mergeSort(int a[], int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    int *x=(int*)malloc(sizeof(int)*10000000);
    int *y=(int*)malloc(sizeof(int)*10000000);
    for(int i=s;i<=mid;i++)
    {
        x[i]=a[i];
    }
    for(int i=mid+1;i<=e;i++)
    {
        y[i]=a[i];
    }
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    merge(a,x,y,s,e);
}

int main()
{
    int n;
    for(n=10;n<=10000000;n*=10)
    {
        int *arr=(int*)malloc(sizeof(int)*n);
        clock_t start, end;
        for(int i=0;i<n;i++)
        {
            arr[i]=n-i;
        }
        start=clock();
        mergeSort(arr,0,n-1);
        end=clock();
        double time_taken=(double)end-start;
        printf("Time taken: %f\n",time_taken);
        free(arr);
    }
    return 0;
}
