#include<stdio.h>
#include<stdlib.h>

#define size 10

void bfsearch(int adj[][size],int visited[],int start, int n)
{
    int q[size],front=-1,rear=-1;
    q[++rear]=start;
    visited[start]=1;
    printf("%d\t",start);
    while(front!=rear)
    {
        start=q[++front];
        for(int i=0;i<n;i++)
        {
            if(adj[start][i]==1&&visited[i]==0)
            {
                q[++rear]=i;
                visited[i]=1;
                printf("%d\t",i);
            }
        }
    }
}

int main()
{
    int n;
    int ch;
    int v[size];
    for(int i=0;i<size;i++)
    {
        v[i]=0;
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
    bfsearch(adj,v,st,n);
    return 0;
}

/*#include<stdio.h>

int a[20][20],q[20],visited[20],n,f=-1,r=-1;

void bfs(int v)
{
       int i;
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(a[v][i] != 0 && visited[i] == 0) // adjacent to v and not visited
              {
                       r=r+1;
                       q[r]=i;// insert them into queue
                       visited[i]=1;          // mark the vertex visited
                       printf("%d  ",i);
              }
      }
      f=f+1;// remove the vertex at front of the queue
      if(f<=r)                           // as long as there are elements in the queue
            bfs(q[f]);                  // peform bfs again on the vertex at front of the queue
}
int main()
{
    int v,i,j;
    int ch;
    printf("\n Enter the number of vertices:");
    scanf("%d",&n);
    for (i=0;i<n;i++) // mark all the vertices as not visited
    {
        visited[i]=0;
    }
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
       scanf("%d",&a[i][j]);
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    f=r=0;
    q[r]=v;
    printf("\n BFS traversal is:\n");
    visited[v]=1;  // mark the starting vertex as visited
    printf("%d   ",v);
    bfs(v);
    if(r != n-1)
        printf("\n BFS is not possible");
}*/
