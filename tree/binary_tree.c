#include<stdio.h>
#include<stdlib.h>

typedef struct n
{
    int data;
    struct node *left,*right;
}node;

node* create()
{
    node* p;
    printf("Enter value of the node(-1 for no node): ");
    int q;
    scanf("%d",&q);
    p=(node*)malloc(sizeof(node));
    if(q==-1)
    {
        return NULL;
    }
    p->data=q;
    printf("Enter the left node of %d(-1 for no node): ",q);
    p->left=create();
    printf("Enter the right node of %d(-1 for no node): ",q);
    p->right=create();
    return p;
}

void preorder(node *root)
{
    if(root)
    {
        printf("%d\t",root->data);
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
        printf("%d\t",root->data);
    }
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d",&root->data);
        inorder(root->right);
    }
}

int main()
{
    node *ptr=create();
    preorder(ptr);
    return 0;
}