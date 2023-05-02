#include<iostream>
using namespace std;

template <class T>

void swap_numbers(T&x, T&y)
{
    T t;
    t=x;
    x=y;
    y=t;
}

int main()
{
    int a,b;
    float m,n;

    cout<<"Enter two integers: ";
    cin>>a>>b;

    cout<<"Enter two float numbers: ";
    cin>>m>>n;

    swap_numbers(a,b);
    cout<<"a and b after swapping: "<<a<<" "<<b<<endl;
    swap_numbers(m,n);
    cout<<"m and n after swapping: "<<m<<" "<<n<<endl;
    return 0;
}