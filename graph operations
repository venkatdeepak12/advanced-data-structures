
// inserting,deletion of edges and vertices,displaying the graph
#include<stdlib.h>
int a[50][50];
int v;
void createGraph()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("enter a[%d][%d] edge:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void insertedge()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			//if((i==v1&&j==v2)||(i==v2&&j==v1))
            if(i==v-1||j==v-1)
			{
				printf("enter a[%d][%d] edge:",i,j);
				scanf("%d",&a[i][j]);
			}
		}
	}
}
void insertvertex()
{
	int i,j;
	v=v+1;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i==v-1||j==v-1)
			{
				a[i][j]=0;
			}
		}
	}
}
void deleteedge()
{
	int i,j,v1,v2;
	printf("enter two vertices v1 and v2:");
	scanf("%d %d",&v1,&v2);
	a[v1][v2]=a[v2][v1]=0;
	printf("edge deleted\n");
}
void deletevertex()
{
	int i,j,d;
	printf("enter vertex to be deleted:");
	scanf("%d",&d);
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i==d||j==d)
			{
				a[i][j]=0;
			}
		}
	}
	printf("vertex deleted\n");
}
void display()
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(a[i][j]!=0)
			{
				printf("the edge from v%d to v%d is %d\n",i,j,a[i][j]);
			}
		}
	}
}
int main()
{
	int choice;
	printf("enter no of vertices:");
	scanf("%d",&v);
	while(1) {
		printf("\n****MENU****\n1.CreateGraph\n2.Insert Vertex\n3.Insert Edge\n4.Delete vertex\n5.Delete Edge\n6.Display\n7.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: createGraph();
                                                         break;
			case 2: insertvertex();
                                                         printf("\nVertex Inserted\n");
			             break;
			case 3: insertedge();
			             break;
			case 4: deletevertex();
			             break;
			case 5: deleteedge();
			              break;
			case 6: display();
			              break;
			case 7: exit(0);
			default: printf("Invalid Selection.");
		}
	}
	return 0;
}
