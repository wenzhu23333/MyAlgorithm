#include<stdio.h>
#include<stdlib.h>
typedef struct dulnode
{
    int data;
    struct dulnode *prior;
    struct dulnode *next;
}dulnode,*dulinklist;

//双向链表中确定链表长度，得到某个元素，定位某个元素，与单向链表差别不大

//插入 删除需要修改两个方向上的指针

dulinklist getelem_dul(dulinklist l,int i)
{
    dulinklist p;
    p=l;
    int j=0;
    while(p->next!=NULL&&j<=i)
    {
    p=p->next;
    j++;
    }
    return p;

}


int listinsert_dul(dulinklist &l,int i,int e)
{
    dulinklist p,s;
    p=getelem_dul(l,i);
    s=(dulinklist)malloc(sizeof(dulnode));
    scanf("%d",s->data);
    s->next=p->next;
    p->next=s;
    p->next->prior=s;
    s->prior=p;
    return 1;

}


int listdelete_dul(dulinklist &l,int i,int &e)

{
    dulinklist p;
    p=getelem_dul(l,i);
    e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    return 1;

}


