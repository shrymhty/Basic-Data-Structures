#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class TreeNode
{
    public:
    T data;
    vector <TreeNode<T>*> children;
    TreeNode(T data)
    {
        this->data=data;
    }
};

TreeNode<int>* input()
{
    int num;
    cout<<"Enter value of node: ";
    cin>>num;
    TreeNode<int>* node=new TreeNode<int>(num);
    int n;
    cout<<"Enter the number of children: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        TreeNode<int>* child=input();
        node->children.push_back(child);
    }
    return node;
}

void printree(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    /*cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++)
    {
        
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        printree(root->children[i]);
    }*/
    cout<<root->data<<"\t";
    for(int i=0;i<root->children.size();i++)
    {
        printree(root->children[i]);
    }
}

int numberofnodes(TreeNode<int>* root)
{
    int ans=1;
    if(root==NULL)
    {
        return 0;
    }
    for(int i=0;i<root->children.size();i++)
    {
        ans+=numberofnodes(root->children[i]);
    }
    return ans;
}

int height(TreeNode<int>* root)
{
    int max=0;
    for(int i=0;i<root->children.size();i++)
    {
        int childheight=height(root->children[i]);
        if(childheight>max)
        {
            max=childheight;
        }
    }
    return max+1;
}

int number_of_leaf_nodes(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->children.size()==0)
    {
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=number_of_leaf_nodes(root->children[i]);
    }
    return ans;
}

int main()
{
    TreeNode<int>* root=input();
    cout<<"\nThe user defined generic tree is: "<<endl;
    printree(root);
    printf("\nThe number of nodes: %d",numberofnodes(root));
    printf("\nThe height of the tree: %d",height(root));
    return 0;
}