#include<iostream>
#include<iomanip>
using namespace std;

template <class T1, class T2>
class Test
{
    T1 a;
    T2 b;
    public:
    Test(T1 x, T2 y)
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
    cout<<"Instantiasing the Test templateclass wiht float and int data types\n";
    Test <float,int> t(3.21,66.3);
    t.show();
    cout<<"Instantiating the Test template class with class and int data types\n";
    Test <char,int> t2('@',303);
    t2.show();
    return 0;
}