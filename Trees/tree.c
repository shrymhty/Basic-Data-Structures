#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node* left, *right;
}tree;

tree* create()
{
    tree* p;
    int q;
    printf("Enter the value of node(-1 for no node): ");
    scanf("%d",&q);
    p=(tree*)malloc(sizeof(tree));
    if(q==-1)
    {
        return NULL;
    }
    p->info=q;
    printf("Enter the left node of %d: \n",q);
    p->left=create();
    printf("Enter the value of right node of %d: \n",q);
    p->right=create();
    return p;
}

tree* inorder(tree* root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}

tree* preorder(tree* root)
{
    if(root)
    {
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    tree* ptr=create();
    printf("\nPreorder Traversal: \n");
    preorder(ptr);
    printf("\nInorder Traversal: \n");
    inorder(ptr);
    return 0;
}