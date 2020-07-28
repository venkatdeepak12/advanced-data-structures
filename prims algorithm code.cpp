#include<iostream>
using namespace std;
int a[100][100],v[100],id,sum,c,n;
void prims() {
    int mi,k,j,i;
    cout<<"\n"<<id<<"->"; 
    --id;
    v[id]=1;
    while(c!=n-1) {
            mi = 10000;
        for(i=0;i<n;++i) {
            if(v[i] == 1) {
                for(j=0;j<n;++j) {
                        if(v[j]==0 && a[i][j]!=0) {
                          if(mi > a[i][j] ) {
                            mi=a[i][j];
                            k=j;
                            }
                        }
                }
            }
        }
        v[k]=1;
        sum=sum+mi;
        cout<<k+1<<"->";
        ++c;
    }
    cout<<"\nMinimum cost spanning tree is:"<<sum;
}
int main() 
{
    int i,j;
    cout<<"Enter no of vertices : ";
    cin>>n;
	cout<<"Enter adjacency matrix : ";
	for(i=0;i<n;++i)
{
		for(j=0;j<n;++j)
{
			cin>>a[i][j];
		}
	}
		cout<<"\nEnter starting vertex";
		cin>>id;
		prims(); 
    return 0;
    }
