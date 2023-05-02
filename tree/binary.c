#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int info;
    struct node* left;
    struct node *right;
}nnode;

int max(int a, int b)
{
    return a>b?a:b;
}

int maxHeight(nnode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else 
    {
        int Rheight=maxHeight(root->right);
        int Dheight=maxHeight(root->left);
        return (max(Rheight,Dheight)+1);
    }
}

nnode* new_node(int x)
{
    nnode* temp=(nnode*)malloc(sizeof(nnode));
    if(temp==NULL){
        printf("Out of memory space\n");
        exit(0);
    }
    temp->info=x;
    temp->left=temp->right=NULL;
    return temp;
}

nnode *insert(nnode* root,int x)
{
    if(root==NULL)
    {
        return new_node(x);
    }
    else if(x>root->info)
    {
        root->right=insert(root->right,x);
    }
    else 
    {
        root->left=insert(root->left,x);
    }
    return root;
}

nnode* search(int x, nnode* root)
{
    if(root==NULL||root->info==x)
    {
        return root;
    }
    else if(x>root->info)
    {
        search(x,root->right);
    }
    else 
    {
        search(x,root->left);
    }
}


void preorder(nnode *root)
{
    if(root)
    {
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(nnode *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}

void inorder(nnode *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}


int main()
{
    char c;
    int val;
    int depth;
    nnode* ptr;
    nnode* temp; 
    printf("Enter the value of the root: ");
    scanf("%d",&val);
    ptr=new_node(val);
    do
    {
        printf("Enter the value to be inserted: ");
        scanf("%d",&val);
        insert(ptr,val);
        printf("Enter n to exit, any key to continue: ");
        getchar();
        scanf("%c",&c);
    } while (c!='n');
    
    printf("\nEnter the number whose depth is to be found: ");
    scanf("%d",&val);
    temp=search(val,ptr);
    if(temp)
    {

        printf("Value found!\n");
        depth=maxHeight(ptr)-maxHeight(temp);
        printf("The depth of %d is %d\n\n",temp->info,depth);
    }
    else
    {
        printf("Not found");
    }
    printf("Inorder traversal: \n");
    inorder(ptr);
    printf("\nPreorder Traversal: \n");
    preorder(ptr);
    printf("\nPostorder traversal: \n");
    postorder(ptr);
    printf("\nThe height of the binary tree is: %d",maxHeight(ptr));
    return 0;
}


