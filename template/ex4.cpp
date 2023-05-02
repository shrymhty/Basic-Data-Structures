//using default data types

#include<iostream>
using namespace std;

template <class T1=int,class T2=int>
class Test
{
    T1 a;
    T2 b;
    public:
    Test(T1 x,T2 y)
    {
        a=x;
        b=y;
    }

    void show()
    {
        cout<<a<<" and "<<b<<endl;
    }
};

int main()
{
    Test<float,int> ob1(3.2,7);
    Test<float,char> ob2(4.20,'y');
    Test <> ob3(2.1,'y');
    ob1.show();
    ob2.show();
    ob3.show();
    return 0;
}