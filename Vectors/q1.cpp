#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v[3]=0;
    v[4]=0;
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    v.push_back(4);
    v.push_back(5);
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    return 0;
}