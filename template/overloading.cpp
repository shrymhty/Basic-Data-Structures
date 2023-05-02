#include<iostream>
using namespace std;

template <class T>
void display(T x)
{
    cout<<"X: "<<x<<endl;
}

template<class T, class T1>
void display(T x, T1 y)
{
    cout<<"X: "<<x<<"\tY: "<<y<<endl;
}

int main()
{
    int a;
    char ch;
    float b;

    cout<<"Enter a integer, float and character: ";
    cin>>a>>ch>>b;
    display(a);
    display(ch,b);
    return 0;                                      
} 