//写在前面：所有的文件都必须建立cpp格式，因为如果建立的是c格式，那么则不能使用&l，也就是引用的概念。
#include<stdio.h>
#include<stdlib.h>
typedef struct {
int ceof;//系数
int expn;//指数

}term,elemtype;
//elemtype是上面定义的数据类型
typedef struct lnode
{
    elemtype data;
    struct lnode * next;

}lnode,*linklist;
//设置链表中元素的指数和系数
void setcurelem(linklist &l,term e)
{
    scanf("%d",&e.ceof);
    scanf("%d",&e.expn);
    l->data=e;
}
//建立多项式函数
void creatpolyn(linklist &l,int m)
{
    l=(linklist)malloc(sizeof(lnode));
    l->next=NULL;
    linklist p;
    term e;
    int i=0;
    for(i;i<m;i++)
    {
        p=(linklist)malloc(sizeof(lnode));
        p->next=l->next;
        l->next=p;
        setcurelem(p,e);
    }

}
//将q插入到链表中p节点的前面
void insert_ployn(linklist &l,linklist &p,linklist &q)
{
    linklist m;
    m=l;
    while(m->next!=p)
    m=m->next;
    m->next=q;
    q->next=p;

}
//两个多项式相加,并将和多项式赋给前一个多项式
void addpolyn(linklist &a,linklist &b)
{
    linklist p,q;//p,q在链表中来回移动
    linklist m,n;//m,n记录a和b的头节点
    p=a->next;
    q=b->next;
    int sum;
    while(p&&q)
    {
        if(p->data.expn<q->data.expn)
            p=p->next;
        else if(p->data.expn==q->data.expn)
        {
            sum=p->data.expn+q->data.expn;
            if(0==sum)
                p->next=p->next->next;//这样写不能释放节点

            else
            {
                p->data.expn=sum;
            }
            p=p->next;
            q=q->next;
        }
        else(p->data.expn>q->data.expn)
        {
            insert_ployn(a,p,q);
            q=q->next;
        }
    }
    if(!p) append(a,q);
    return p;

}


//两个一元多项式相乘




int main()
{
    linklist p;
    creatpolyn(p,3);

}
