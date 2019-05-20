#include<stdio.h>
#include<stdlib.h>

int a[10][10], visited[10], queue[100], qv=-1;

void bfs(int i) 
{
    int j;
    printf("%d\t", i);
    visited[i] = 1;    // mark it as visited

    //enqueue the value
    qv++;
    queue[qv] = i;

    while(qv != -1) {
        //dequeue and store value in i
        i = queue[qv];
        qv--;
	// find adjacent unvisited vertices of i
        for(j=0; j<n; ++j){
            if(visited[j]==0 && a[i][j]!=0) {
                printf("%d\t", j);
                visited[j] = 1;
                qv++;
		// enqueue the value
                queue[qv] = j;
            }
        }
    }
}

int main() 
{
	int i, j, start,n;

	printf("Enter no.of vertices");
	scanf("%d", &n);	

	printf("Enter the adjacency matrix: \n");
	for(i=0; i<n; ++i) {
		for(j=0; j<n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("Enter the starting vertex: ");
	scanf("%d", &start);
	for(i=0; i<n; ++i) {
		visited[i] = 0;
	}

	printf("Starting vertex: %d\n", start);
	printf("Visited vertices: ");
	bfs(start);
	return 0;
}
