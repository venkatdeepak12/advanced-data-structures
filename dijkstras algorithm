#include<stdio.h>
#include<conio.h>
void dijkstra(int,int);
int mat[100][100];
int known[100],path[100],cost[100];

int main()
{
    int i,j,x,n,c=0;
    printf("enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        known[i]=0;
        path[i]=-1;
        cost[i]=10000000; //max value
    }
    printf("enter the matrix of graph:\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&mat[i][j]);
    printf("enter the starting vertex:");
    scanf("%d",&x);
    dijkstra(x,n);
    for(i=0;i<n;i++)
    printf("\nmin cost (%d,%d)=%d\n",x,i,cost[i]);
    return 0;
}

void dijkstra(int x,int n)
{
    int i,j,k;
    known[x]=1;
    cost[x]=0;
    for(i=0;i<n;i++)
    if(mat[x][i]!=0)
    {
        cost[i]=mat[x][i];
        path[i]=x;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
            if(known[j]==0)
            {
                k=j;
                break;
            }
        for(;j<n;j++)
            if(known[j]==0 && cost[j]<cost[k])
                k=j;
        known[k]=1;
        for(j=0;j<n;j++)
        {
            if(known[j]==0)
            if(mat[k][j]!=0 && (cost[k]+mat[k][j])<cost[j])
             {
                cost[j]=cost[k]+mat[k][j];
                path[j]=k;
             }
        }
    }
}

