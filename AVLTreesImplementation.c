#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,h;
    struct node *left,*right;
}; 
struct node* insert(struct  node*,int);
void inorder(struct node*);
struct node* delete1(struct node*,int);
void preorder(struct node*);
void postorder(struct node*);
int balance(struct node*);
int height(struct node*);
struct node* rotateleft(struct node*);
struct node* rotateright(struct node*);
struct node* checkbalance(struct node*);

int main()
{
    int i,j,x,c;
    struct node *p= NULL;
    while(1)
    {
     printf("\n1.insert\n2.delete\n3.print\n4.exit\nenter your choise:");
     scanf("%d",&c);
     if(c==1)
        {
          printf("\nenter element");
          scanf("%d",&x);
          p=insert(p,x);
        }
     else if(c==2)
        {
            printf("\n enter the element:");
            scanf("%d",&x);
            p=delete1(p,x);
        }
    else if(c==3)
        {
            inorder(p);
            printf("\n");
            preorder(p);
            printf("\n");
            postorder(p);
            printf("\n");
        }
    else
        break;
    }

    return 0;
}

struct node* insert(struct node *pr , int d)
{
    struct node *temp1,*temp2;
    if(pr==NULL)
    {
        pr= (struct node*) malloc(sizeof(struct node));
        pr->data=d;
        pr->h=1;
        pr->left=pr->right=NULL;
        printf("(%d,%d)\n",pr->data,pr->h);
        return pr;
    }
    if((pr->data)==d)
    {
        printf("this element is duplicate\n");
        return pr;
    }
    else if((pr->data)<d)
        pr->right=insert(pr->right,d);
    else
        pr->left=insert(pr->left,d);
    pr=checkbalance(pr);
    return pr;
}

struct node* checkbalance(struct node  *pr)
{
    int bf1,bf2;
    struct node *temp1;
    bf1=balance(pr);
    if(bf1==2)
    {
        bf2=balance(pr->left);
        if(bf2==-1)
          pr->left=rotateleft(pr->left);
        temp1=rotateright(pr);
        return (temp1);
    }
    else if(bf1==-2)
    {
       bf2=balance(pr->right);
        if(bf2==1)
            pr->right=rotateright(pr->right);
        temp1=rotateleft(pr);
        return(temp1);
    }
    pr->h= height(pr);
    return pr;
}

int height(struct node *pr)
{
    int h1=0,h2=0;
    if((pr->left)!= NULL)
        h1=(pr->left)->h;
    if(pr->right!=NULL)
        h2=(pr->right)->h;
    if(h1>h2)
    return(h1+1);
    else
    return(h2+1);
}
int balance(struct node *pr)
{
   int h1,h2;
   if(pr->left==NULL)
    h1=0;
   else
    h1= (pr->left)->h;
   if(pr->right==NULL)
    h2=0;
    else
    h2=pr->right->h;
    return(h1-h2);
}

struct node* rotateleft(struct node *pr)
{
    struct node *x;
    x=pr->right;
    pr->right=x->left;
    x->left=pr;
    pr->h=height(pr);
    x->h=height(x);
    return x;
}

struct node* rotateright(struct node *pr)
{
    struct node *x;
    x=pr->left;
    pr->left=x->right;
    x->right=pr;
    pr->h=height(pr);
    x->h=height(x);
    return x;
}

int  leftmost(struct node *p)
{
    p=p->left;
    while(p->right!=NULL)
    p=p->right;
    printf("data %d",p->data);
    return p->data;
}

struct node* delete1(struct node *p,int d)
{
    struct node *temp1,*temp2;
    int data;
    if(p==NULL)
    {
        printf("element not found");
        return(NULL);
    }

    if((p->data)==d)
    {
        if(p->left==NULL)
        {
            temp1=p->right;
            free(p);
        }
        else if(p->right==NULL)
        {
            temp1=p->left;
            free(p);
        }
        else
        {
            data=leftmost(p);
            p->data=data;
            p->left=delete1(p->left,data);
            temp1=p;
        }
        if(temp1!=NULL)
        temp1=checkbalance(temp1);
        return(temp1);
    }
    if((p->data)>d)
    {
        p->left=delete1(p->left,d);
    }
    else
    p->right=delete1(p->right,d);
    p=checkbalance(p);
    return p;
}

void inorder(struct node *p)
{
    if(p==NULL)
    return;
    inorder(p->left);
    printf("%d ",p->data);
    inorder(p->right);
}

void preorder(struct node *p)
{
    if(p==NULL)
    return;
    printf("%d ",p->data);
    preorder(p->left);
    preorder(p->right);
}
void postorder(struct node *p)
{
    if(p==NULL)
    return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ",p->data);
}
