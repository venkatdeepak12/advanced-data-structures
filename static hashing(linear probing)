#include<stdio.h>
int a[10],n=10,count=0;
void insertk(int);
void deletek(int);
int main()
{
    int i,c,v;
    for(i=0;i<n;i++)
    a[i]=-1;
    while(1)
    {
        printf("\n1.insert\n2.delete\n3.print\n4.exit\nenter your choise");
        scanf("%d",&c);
     if(c==1)
            {
               printf("enter the element to insert:");
               scanf("%d",&v);
               insertk(v);
            }
     else if(c==2)
            {
               printf("enter the element to delete:");
               scanf("%d",&v);
               deletek(v);
            }
    else if(c==3)
        for(i=0;i<n;i++)
        printf("%d ",a[i]);
    else
        break;
    }
    return 0;
}

void insertk(int v)
{
    int l=0;
    if(count==n)
    {
        printf("memory full");
        return;
    }
    while(a[(v+l)%n]!=-1)
    l++;
    a[(v+l)%n]=v;
    count++;
}

void deletek(int v)
{
    int l=0,t,s;
    while(a[(v+l)%n]!=v)
    {
        if(a[(v+l)%n]==-1)
        {
            printf("element does not exist");
            return;
        }
        l++;
    }
    t=v+l;
    a[t%n]=-1;
    t++;
    while(a[t%n]!=-1)
    {
       s=a[t%n];
       a[t%n]=-1;
       count--;
       insertk(s);
       t++;
    }
    printf("element is deleted");
    count--;
}
