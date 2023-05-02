#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int info;
    struct tree *right;
    struct tree *left;
}node;

node *new_node(int x)
{
    node* nnode=(node*)malloc(sizeof(node));
    if(nnode==NULL)
    {
        printf("Out of memory space");
    }
    nnode->info=x;
    nnode->left=nnode->right=NULL;
    return nnode;
}

node *insert(node* root, int x)
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

node *search(int x, node* root)
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

node* iterativesearch(int x,node* root)
{
    while(root)
    {
        if(x==root->info)
        {
            return root;
        }
        else if(x>root->info)
        {
            root=root->right;
        }
        else 
        {
            root=root->left;
        }
    }
    return root;
}

int max(int a, int b)
{
    return a>b?a:b;
}

node* maximum(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->right!=NULL)
    {
        return maximum(root->right);
    }
    return root;
}

node* minimum(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left!=NULL)
    {
        return minimum(root->left);
    }
    return root;
}

node* delete(int x, node* root)
{
   if(root==NULL)
   {
        return NULL;
   }
   else if(x<root->info)
   {
        delete(x,root->left);
   }
   else if(x>root->info)
   {
        delete(x,root->right);
   }
   else
    {
        if(root->right==NULL&&root->left==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left==NULL||root->left==NULL)
        {
            node* temp;
            if(root->left==NULL)
            {
                temp=root->right;
            }
            else 
            {
                temp=root->left;
            }
            free(root);
            return temp;
        }
        else 
        {
            node* temp=minimum(root->right);
            root->info=temp->info;
            free(delete(temp->info,root->right));
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
        return (max(Lheight,Rheight)+1);
    }
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}

void preorder(node* root)
{
    if(root)
    {
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}

int count(node *root)
{
    int c=1;
    if(root == NULL){
        return 0;
    }
    else
    {
        /*c+=count(root->left);
        c+=count(root->right);
        return c;*/
        return 1+count(root->left)+count(root->right);
    }
}

int main()
{
    node* root;
    root=new_node(20);
    insert(root, 9);
    insert(root, 10);
    insert(root, 15);
    insert(root, 6);
    insert(root, 12);
    insert(root, 17);
    insert(root, 2);
    printf("Inorder Traversal: \n");
    inorder(root);
    printf("\nPostorder Traversal: \n");
    postorder(root);
    printf("\nPreorder Traversal: \n");
    preorder(root);
    printf("\nHeight of the tree: %d",height(root));
    printf("\nNumber of nodes in the tree: %d",count(root));
    printf("\nEnter the number to be searched: ");
    int num;
    scanf("%d",&num);
    if(search(num,root))
    {
        printf("Node found\n");
    }
    else 
    {
        printf("Node not found\n");
    }
    printf("Largest number in the BST: %d",maximum(root)->info);
    printf("\nSmallest value in the BST: %d",minimum(root)->info);
    return 0;
}