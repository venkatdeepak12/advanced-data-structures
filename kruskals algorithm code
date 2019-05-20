#include <bits/stdc++.h>
using namespace std;
int parent[100],cost[100][100],n,sum;
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
void kruskals() {
    int mincost = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int edge_count = 0;
    while (edge_count < n - 1) {
        int min = 9999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j]!=0 && find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        cout<<"Edge "<<edge_count++<<"("<<a+1<<","<<b+1<<") cost:"<< min<<endl;
        sum += min;
    }
}

int main()
{
    int i,j;
    cout<<"Enter no of vertices : ";
    cin>>n;
	cout<<"Enter adj matrix";
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			cin>>cost[i][j];
			}
		}
    kruskals();
   cout<<"\n Minimum cost ="<<sum;
    return 0;
}
