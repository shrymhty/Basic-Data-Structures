#include<stdio.h>

#define size 10
int stack[size];
int visited[size];
int top=-1;
int n;


void dfsearch(int adj[][size],int visited[], int start)
{
    int i;
    stack[++top]=start;
    visited[start]=1;
    printf("%d\t",start);
    while(top!=-1)
    {
        start=stack[top];
        for(i=0;i<n;i++)
        {
            if(adj[start][i]==1&&visited[i]==0)
            {
                visited[i]=1;
                stack[++top]=i;
                printf("%d\t",i);
                break;
            }
        }
        if(i==size)
        {
            top--;
        }
    }
}

int main()
{
    int n;
    int ch;
    for(int i=0;i<size;i++)
    {
        visited[i]=0;
    }
    int st;
    printf("Enter the order of the adjacency matrix: ");
    scanf("%d",&n);
    int adj[n][n];
    printf("Enter 1: Create edge\nEnter 0: No edge\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Edge between %d and %d\n",i,j);
            printf("Enter choice[0/1]: ");
            scanf("%d",&adj[i][j]);
        }
    }
    printf("The node that starts: ");
    for(int i=0;i<n;i++)
    {
        printf("%d, ",i);
    }
    scanf("%d",&st);
    dfsearch(adj,visited,st);
    return 0;
}
