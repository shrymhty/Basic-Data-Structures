#include<iostream>
using namespace std;

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int cap)
    {
        arr=new int(cap);
        front=0;
        rear=-1;
        size=0;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
    void push(int num)
    {
        if(rear==size)
        {
            cout<<"Queue overflow"<<endl;
        }
        rear+=1;
        arr[rear]=num;
    }
    int pop()
    {
        if(rear<front)
        {
            cout<<"Queue Underflow"<<endl;
            return 0;
        }
        int d;
        d=arr[front];
        front=front+1;
        return d;
    }
    void display()
    {
        if(rear<front)
        {
            cout<<"Empty"
        }
    }
};