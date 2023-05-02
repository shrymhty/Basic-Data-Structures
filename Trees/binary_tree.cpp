#include<iostream>
#include<queue>
using namespace std;

template <typename T>

class BNode
{
    public:
    T data;
    BNode* right,*left;
    BNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }    
    ~BNode()
    {
        delete right;
        delete left;
    }
};

BNode<int>* input()
{
    cout<<"Enter the value of the root(-1 for no node): ";
    int num;
    cin>>num;
    if(num==-1)
    {
        return NULL;
    }
    BNode<int>* node=new BNode<int>(num);
    cout<<"Enter the left node "<<endl;
    node->left=input();
    cout<<"Enter the right node "<<endl;
    node->right=input();
    return node;
}

BNode<int>* input_level_wise()
{
    queue<BNode<int>*> q;
    int num;
    cout<<"Enter node value: ";
    cin>>num;
    if(num==-1)
    {
        return NULL;
    }
    BNode<int>* node=new BNode<int>(num);
    q.push(node);
    while(!q.empty())
    {
        BNode<int>* f=q.front();
        q.pop();
        cout<<"Enter the left child of "<<f->data<<": ";
        cin>>num;
        if(num!=-1)
        {
            BNode<int>* child=new BNode<int>(num);
            q.push(child);
            f->left=child;

        }
        cout<<"Enter the right child of "<<f->data<<": ";
        cin>>num;
        if(num!=-1)
        {
            BNode<int>* child=new BNode<int>(num);
            q.push(child);
            f->right=child;
        }     
    }
    return node;
}

bool helper(BNode<int>* rightTree, BNode<int>* leftTree)
{
    if(rightTree==NULL&&leftTree!=NULL) return false;
    if(rightTree!=NULL&&leftTree==NULL) return false;
    if(rightTree->data!=leftTree->data) return false;
    if(leftTree==NULL&&rightTree==NULL) return true;
    
    return helper(rightTree->right, leftTree->left) && helper(leftTree->right,rightTree->left);
}

bool symmetric(BNode<int>* root)
{
    if(root==NULL) return true;
    return helper(root->left,root->left);
}

void traversal(BNode<int>* root)
{
    if(root)
    {
        cout<<root->data<<"\t";
        traversal(root->left);
        traversal(root->right);        
    }
}

int maximum(int a, int b)
{
    return (a>b?a:b);
}
int height(BNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int Rheight=height(root->right);
    int Lheight=height(root->left);
    return (max(Rheight,Lheight)+1);
}

void level_traversal(BNode<int>* root)
{
    queue<BNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BNode<int>* f=q.front();
        cout<<f->data<<"\t";
        q.pop();
        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }
    }
}

int count_nodes(BNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return count_nodes(root->left)+count_nodes(root->right)+1;
}

bool findNode(BNode<int>* root, int x)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    return (findNode(root->left,x) || findNode(root->right,x));
}

int main()
{
    int n;
    BNode<int>* root=input_level_wise();
    cout<<"The user defined binary tree: \n";
    level_traversal(root);
    cout<<"\n"<<count_nodes(root);
    cout<<"Enter the node to be found: ";
    cin>>n;
    if(findNode(root,n))
    {
        cout<<"Node found"<<endl;
    }

    else 
    {
        cout<<"Node not found"<<endl;
    }
    //delete root;
    return 0;
}