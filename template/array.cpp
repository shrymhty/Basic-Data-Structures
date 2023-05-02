#include<iostream>
using namespace std;

template <class T>

void sort(T arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;i<j;j--)
        {
            T temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
        }
    }
}

template <class T1>
void display(T1 arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}

int main()
{
    int num;
    cout<<"Enter the number of elements: ";
    cin>>num;
    int intarr[num];
    float floatarr[num];
    cout<<"Enter the elements of the integer array: ";
    for(int i=0;i<num;i++)
    {
        cin>>intarr[i];
    }
    cout<<"\nEnter the elements of the float array: ";
    for(int i=0;i<num;i++)
    {
        cin>>floatarr[i];
    }

    cout<<"Integer array after sorting: \n";
    sort(intarr,num);
    display(intarr,num);

    cout<<"Float array after sorting: \n";
    sort(floatarr,num);
    display(floatarr,num);
    return 0;
}