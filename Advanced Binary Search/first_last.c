#include<stdio.h>
#include<stdlib.h>

int first_occurence(int a[], int target)
{
    int s=0;
    int e=7;
    int idx=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==target)
        {
            idx=mid;
            e=mid-1;
        }
        else if(a[mid]<target)
        {
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }
    }
    return idx;
}

int last_occurence(int a[], int target)
{
    int s=0;
    int e=7;
    int idx=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==target)
        {
            idx=mid;
            s=mid+1;
        }
        else if(a[mid]<target)
        {
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }
    }
    return idx; 
}

int* indexes(int a[], int target)
{
    int* arr=(int*)malloc(sizeof(int)*2);
    arr[0]=arr[1]=-1;
    if(first_occurence(a,target)==-1)
    {
        return arr;
    }
    arr[0]=first_occurence(a,target);
    arr[1]=last_occurence(a,target);
    return arr;
}

int main()
{
    int input[]={1,2,3,5,5,5,6,7};
    int* res=(int*)malloc(sizeof(int)*2);
    res=indexes(input,5);
    for(int i=0;i<2;i++)
    {
        printf("%d, ",res[i]);
    }
    return 0;
}