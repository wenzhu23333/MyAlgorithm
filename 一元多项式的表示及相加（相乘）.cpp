//д��ǰ�棺���е��ļ������뽨��cpp��ʽ����Ϊ�����������c��ʽ����ô����ʹ��&l��Ҳ�������õĸ��
#include<stdio.h>
#include<stdlib.h>
typedef struct {
int ceof;//ϵ��
int expn;//ָ��

}term,elemtype;
//elemtype�����涨�����������
typedef struct lnode
{
    elemtype data;
    struct lnode * next;

}lnode,*linklist;
//����������Ԫ�ص�ָ����ϵ��
void setcurelem(linklist &l,term e)
{
    scanf("%d",&e.ceof);
    scanf("%d",&e.expn);
    l->data=e;
}
//��������ʽ����
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
//��q���뵽������p�ڵ��ǰ��
void insert_ployn(linklist &l,linklist &p,linklist &q)
{
    linklist m;
    m=l;
    while(m->next!=p)
    m=m->next;
    m->next=q;
    q->next=p;

}
//��������ʽ���,�����Ͷ���ʽ����ǰһ������ʽ
void addpolyn(linklist &a,linklist &b)
{
    linklist p,q;//p,q�������������ƶ�
    linklist m,n;//m,n��¼a��b��ͷ�ڵ�
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
                p->next=p->next->next;//����д�����ͷŽڵ�

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


//����һԪ����ʽ���




int main()
{
    linklist p;
    creatpolyn(p,3);

}
