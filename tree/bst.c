//binary search tree

#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

int maximum(int a,int b)
{
    return a>b?a:b;
}

node *nnode(int x)
{
    struct node *p;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    p->left=p->right=NULL;
    return p;
}

node* new_node(int x)
{
    node *nnode=(node*)malloc(sizeof(node));
    if(nnode==NULL)
    {
        printf("Out of memory space\n");
        exit(0);
    }
    nnode->data=x;
    nnode->left=nnode->right=NULL;
    return nnode;
}

node *insert(node* root, int x)
{
    if(root==NULL)
    {
        return new_node(x);
    }
    else if(x>root->data)
    {
        root->right=insert(root->right,x);
    }
    else 
    {
        root->left=insert(root->left,x);
    }
    return root;
}

node* search(node* root, int x) //recursive search
{
    if(root==NULL||x==root->data)
    {
        return root;
    }
    else if(x>root->data)
    {
        search(root->right,x);
    }
    else 
    {
        search(root->left,x);
    }
}

node* iterativesearch(node* root, int x)//iterative search
{
    while(root!=NULL)
    {
        if(x==root->data)
        {
            return root;
        }
        else if(x<root->data)
        {
            root=root->left;
        }
        else 
        {
            root=root->right;
        }
    }
    return NULL;
}

node* min(node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left!=NULL)
    {
        return min(root->left);
    }
    return root;
}

node* max(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->right!=NULL)
    {
        return max(root->right);
    }
    return root;
}

node * delete(node* root, int x)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(x<root->data)
    {
        delete(root->left,x);
    }
    else if(x>root->data)
    {
        delete(root->right,x);
    }
    else 
    {
        if(root->left==NULL&&root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL||root->right==NULL)
        {
            node* temp;
            if(root->right==NULL)
            {
                temp=root->left;
            }
            else 
            {
                temp=root->right;
            }
            free(root);
            return temp;
        }
        else 
        {
            node* temp=min(root->right);
            root->data=temp->data;
            free(delete(root->right,temp->data));
        }
    }
    return root;
}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else 
    {
        int Rheight=height(root->right);
        int Lheight=height(root->left);

        return (maximum(Rheight,Lheight)+1);
    }
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root;
    root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);
    printf("Inorder Traversal:\n");
    inorder(root);
    int m=max(root)->data;
    printf("\nMaximum: %d\n",m);
    int minimum=min(root)->data;
    printf("Minimum: %d",minimum);
    int val;
    printf("\nEnter the value to be searched: ");
    scanf("%d",&val);
    if(search(root,val))
    {
        printf("Element %d found",val);
    }
    else 
    {
        printf("Element not found\n");
    }
    insert(root,2);
    printf("\n");
    inorder(root);
    delete(root,20);
    printf("\nInorder Traversal:\n");
    inorder(root);
    printf("\nHeight of the binary search tree: %d",height(root));
    return 0;
}
