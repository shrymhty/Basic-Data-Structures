#include<iostream>
using namespace std;

template <class t>
class test
{
    public:
    test( t c)
    {
        cout<<c<<endl;
        cout<<sizeof(c)<<endl;
    }
};

int main()
{
    test <float> t1(1.1);
    test <int> t2(5);
    test <char> t3('F');
    return 0;
}
