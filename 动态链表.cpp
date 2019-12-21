#include<stdio.h>

typedef  struct lnode
{
    int data;
    struct lnode *next;

}lnode,*linklist;
//typedef为C语言的关键字，作用是为一种数据类型定义一个新名字。
//这里的数据类型包括内部数据类型（int,char等）和自定义的数据类型（struct等）。
//不能使用lnode直接定义变量，只能通过linklist定义lnode类型的指针（与C++不同）
//结构体在创建时必须初始化，所以不方便直接创建变量，故直接使用变量的指针
typedef int status;
//得到链表中第i个元素
status getelem_l(linklist &l,int i,int &e)
{
    linklist p;
    p=l->next;
    int j
    for(j=1;j<i&&p;j++)
    {
        p=p->next;
    }
    // use while also
    if(!p||j>i) return 0;
    e=p->data;
    return 1;
}

//在链表中插入元素
status list_insert(linklist &l,int i,int e)
//linklist &l 是引用传递 可以起到修改链表的作用
//linklist l 是值传递 传的是l的一个副本 不能修改链表
{
    linklist p,s;
    j=0;
    p=l;
    //L is also an elem ,so j < i-1
      for(j=1;j<i-1&&p;j++)
    {
        p=p->next;
    }
    if(!p||j>i) return 0;
    //use while also
    /*
    while(p&&j<i-1)
    {
    p=p->next;
    ++j;
    }
    */
    s=(linklist)malloc(sizeof(lnode));
    s->next=p->next;
    p->next=s;
    s->data=e;
    //先从本节点后面的节点插入
    return 1;
}

//删除链表中的元素
status deletelist(linklist &l,int i,int &e)
{
    linklist p,q;
    p=l;
    int j=0;

     while(p&&j<i-1)
    {
    p=p->next;
    ++j;
    }
    if(!(p->next)||j>i-1)
    return 0;
    q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    //一定要释放存储空间
    return 1;
}

//尾插法建立链表（需要p和q两个指针变量才能完成链表的动态变化）
void taillist(linklist &l,int n)
{
    l=(linklist)malloc(sizeof(lnode));
    linklist p,q;
    q=l
    int j=0;
    while(j<n)
    {
        p=(linklist)malloc(sizeof(lnode));
        scanf("%d",&p.data);
        q->next=p;
        q=p;
        j++;
    }
    q->next=NULL;
}
//头插法建立链表(只需要使用一个p就能完成链表的动态变化)
void headlist(linklist l,int n)
{
    linklist p;
    l=(linklist)malloc(sizeof(lnode));
    l->next=NULL;
    int j=0;
    while(j<n)
    {
        p=(linklist)malloc(sizeof(lnode));
        scanf("%d",&p.data);
        p->next=l->next;
        l->next=p;
        j++;
    }
}

//将两个有序表合并成一个有序表
void mergelist(linklist &la,linklist &lb,linklist &lc)
{
    linklist x,y,z;
    x=la->next;
    y=lb->next;
    lc=z=la;
    //此处是为了节约空间，将la,lb合并到la处
    while(x&&y)
    {
        if(x->next<=y->next)
       {
        z->next=x;
        z=x;
        x=x->next;
       }
       else
       {
        z->next=y;
        z=y;
        y=y->next;
       }
       z->next=X?x:y;
       free(lb);
       //将lb释放以节约空间
    }




}



int main()

{
   linklist x;
headlist(x);


         }
