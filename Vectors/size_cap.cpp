#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> *vp=new vector<int>(); //dynamic
    vector<int> v; //static

    for(int i=0;i<10;i++)
    {
        v.push_back(i+1);
        cout<<"Size: "<<v.size()<<endl;  
        cout<<"Capacity: "<<v.capacity()<<endl;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}