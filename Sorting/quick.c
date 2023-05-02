#include<stdio.h>
#include<stdbool.h>


#define max 10
int a[max] = { 2,1,6,7,3,8,4,10,9,5 };

void swap(int num1,int num2)
{
    int temp=a[num1];
    a[num1]=a[num2];
    a[num2]=temp;
}


int partition(int left,int right, int pivot)
{
    int leftPointer=left;
    int rightPointer=right-1;
    while(true)
    {
        while(a[leftPointer++]<pivot)
        {
            //do-nothing
        }
        while(rightPointer>0&&a[rightPointer--]>pivot)
        {
            //do-nothing
        }
        if(leftPointer>=rightPointer)
        {
            break;
        }
        else 
        {
            swap(leftPointer,rightPointer);
        }
    }
    swap(leftPointer,right);
    return leftPointer; 
}

void quick(int left,int right)
{
    if(right-left<=0)
    {
        return;
    }
    else 
    {
        int pivot=a[right];
        int partitionPoint=partition(left,right,pivot);
        quick(left,partitionPoint-1);
        quick(partitionPoint+1,right);
    }
}

int main()
{
    for(int i=0;i<9;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    quick(0,9);
    for(int i=0;i<9;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}