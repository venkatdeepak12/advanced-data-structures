#include<stdio.h>
void insert(int);
int deletemin(void);
void swap(int,int); 
int a[100],n=0;
int main()
{
    int cost=0,i,t,x,y;
    printf("enter number of runs:");
    scanf("%d",&t);
    printf("enter no of elements in each runs");
    for(i=0;i<t;i++)
    {
        scanf("%d",&x);
        insert(x);
    }
    while(n>1)
    {
        x=deletemin();
        y=deletemin();
        cost= x+y;
        insert(x+y);
    }
 printf("total cost=%d",cost);
return 0;
}

void insert( int v)
{
    int i,t,j;
    i=n;
    a[n++]=v;
    while(i>0)
    {
        j=(i-1)/2;
        if(a[i]<a[j])
        {
            swap(i,j);
            i=j;
        }
        else
            break;
    }
}

int deletemin()
{
    int i=0,v,j,k;
    if(n==0)
    {
        printf("Heap is empty");
        return -1;
    }
    v=a[0];
    a[0]=a[--n];
    while(2*i+1<n)
    {
       j=2*i+1;
       k=j+1;
       if((a[i]>a[j])&&(a[k]>=a[j]))
        {
            swap(i,j);
            i=j;
        }
       else if(a[i]>a[k] && a[j]>a[k])
        {
            swap(i,k);
            i=k;
        }
        else
        break;
    }
    j=2*i+1;
    if(j<n)
    if(a[j]<a[i])
    swap(i,j);
    return v;
}

void swap(int i,int j)
{
    int t;
    t=a[i];
    a[i]=a[j];    
    a[j]=t;
}
