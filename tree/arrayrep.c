#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 struct node*left;
 struct node*right;
 char data;
}node;

node* insert(char c[],int n)
{ node*tree=NULL;
 if(c[n]!='\0')
 {
  tree=(node*)malloc(sizeof(node));
  tree->left=insert(c,2*n+1);
  tree->data=c[n];
  tree->right=insert(c,2*n+2);
 }
 return tree;
}
//traverse the tree in inorder
void inorder(node*tree)
{
 if(tree)
 {
  inorder(tree->left);
  printf("%c\t",tree->data);
  inorder(tree->right);
 }
}

void main()
{
 node*tree=NULL;
 char c[]={'A','B','C','D','E','F','\0','G','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
 tree=insert(c,0);
 inorder(tree);
}
