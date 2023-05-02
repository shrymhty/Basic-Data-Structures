#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void mergeArrays(int x[],int y[],int a[],int p,int q){
       int mid = (p+q)/2;
       int i=p;
       int j = mid+1;
       int k = p;
       while(i<=mid && j<=q){
           if(x[i] < y[j])
           {
            a[k++] = x[i++];
           }
           else
           {
            a[k++] = y[j++];
           }
       }
       while(i<=mid)
       {
        a[k++] = x[i++];
       }
       while(j<=q)
       {
        a[k++] = y[j++];
       }
}

void mergeSort(int a[],int p,int q){
    if(p>=q)
    {
        return;
    }
    int mid = (p+q)/2;
    int x[100],y[100];
    for(int i=p;i<=mid;i++){ 
        x[i] = a[i];
    }
    for(int i=mid+1;i<=q;i++){
        y[i] = a[i];
    }
    mergeSort(x,p,mid);
    mergeSort(y,mid+1,q);
    mergeArrays(x,y,a,p,q);
}

int main()
{
    /*int a[] = {7,3,10,5,6,2,-5};
    mergeSort(a,0,6);

    for(int i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }*/
    int *arr=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<10;i++)
    {
        arr[i]=10-i;
    }
    clock_t start, end;
    start=clock();
    mergeSort(arr,0,9);
    end=clock();
    double taken=(double)end-start;
    for(int i=0;i<9;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n%f",taken);
    return 0;
}
