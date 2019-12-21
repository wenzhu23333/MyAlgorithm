#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define list_init_size 100
#define listincrement 10
using namespace std;
typedef int status;
typedef int elemtype;
typedef struct lnode
{
elemtype elem;
lnode* next;
}lnode,*linklist;
//线性链表的生成
status creat_linklist(linklist &l,int n)
{
    l=(linklist)malloc(sizeof(lnode));
    linklist p,q;
    q=l;
    int i;
    for(i=0;i<n;i++)
    {
        p=(linklist)malloc(sizeof(lnode));
        cin>>p->elem;
       q->next=p;
       q=p;

    }
    q->next=NULL;
    return 1;
}
//线性链表的插入
status insert_linklist(linklist &l,int n,elemtype m)
{
    linklist p=(linklist)malloc(sizeof(lnode));
    p->elem=m;
    linklist q=l;
    for(int i=0;i<n;i++)
    {
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
    return 1;

}
//线性链表的删除
status delete_linklist(linklist &l,int n)
{
    linklist p,q;
    p=l;
    for(int i=0;i<n;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);

    return 1;
}

status show(linklist l)
{
    linklist p=l;
    if(l->next==NULL)
    {
         cout<<"空链表!";
         return 0;
    }

    while(p->next!=NULL)
    {

        p=p->next;
        cout<<p->elem;
    }

    return 1;

}
//链表的逆置

status reverse_linklist(linklist &l)
{
    linklist p,q;
    p=l;
    int i=0;
    while(p->next!=NULL)
    {
        p=p->next;
        i++;
    }
    q=l->next;
    for(int m=0;m<i-1;m++)
    {

        l->next=q->next;
        q->next=p->next;
        p->next=q;
        q=l->next;
    }
    return 1;
}

int main()
{
linklist l;
creat_linklist(l,3);
insert_linklist(l,1,6);
show(l);
cout<<endl;
reverse_linklist(l);
show(l);
}
