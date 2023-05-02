#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_idx])
            {
                min_idx=j;
            }
            if(min_idx!=i)
            {
                swap(&a[min_idx],&a[i]);
            }
        }
    }
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
        sort(arr,n);
        end=clock();
        double time_taken=(double)end-start;
        printf("Time taken: %f\n",time_taken);
        free(arr);
    }
}