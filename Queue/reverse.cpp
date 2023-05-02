#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int cap;
    int n;
    queue<int> q1;
    queue<int> q2;
    cout<<"Enter capacity: "<<endl;
    cin>>cap;
    for(int i=0;i<cap;i++)
    {
        cin>>n;
        q1.push(n);
    }
    while(!q1.empty())
    {
        cout<<q1.front()<<"\t";
        q2.push(q1.front());
        q1.pop();
    }
    cout<<"\n";
    while(!q2.empty())
    {
        cout<<q2.front()<<"\t";
        q2.pop();
    }
    return 0;
}