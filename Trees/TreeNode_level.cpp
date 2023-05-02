#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>

class TreeNode
{
    public:
    T data;
    vector <TreeNode<T>*> children;
    TreeNode(int data)
    {
        this->data=data;
    }
};

TreeNode<int>* level_input()
{
    queue<TreeNode<int>*> q;
    int num;
    int n;
    cout<<"Enter value of the node: ";
    cin>>num;
    TreeNode<int>* node=new TreeNode<int>(num);
    q.push(node);
    if(!q.empty())
    {
        TreeNode<int>* f=q.front();
        q.pop();
        cout<<"Enter the number of children of "<<f->data<<": ";
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cout<<"Enter value of child "<<i+1<<": ";
            cin>>num;
            TreeNode<int>* child=new TreeNode<int>(num);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return node;
}

void printree(TreeNode<int>* root)
{
    if(root==NULL)
    {
        cout<<"The tree is empty"<<endl;
        return;
    }
    cout<<root->data<<"\t";
    for(int i=0;i<root->children.size();i++)
    {
        printree(root->children[i]);
    }
}

int main()
{
    TreeNode<int>* root=level_input();
    cout<<"User defined generic tree: \n";
    printree(root);
    return 0;
}