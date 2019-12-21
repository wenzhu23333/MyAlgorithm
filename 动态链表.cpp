#include<stdio.h>

typedef  struct lnode
{
    int data;
    struct lnode *next;

}lnode,*linklist;
//typedefΪC���ԵĹؼ��֣�������Ϊһ���������Ͷ���һ�������֡�
//������������Ͱ����ڲ��������ͣ�int,char�ȣ����Զ�����������ͣ�struct�ȣ���
//����ʹ��lnodeֱ�Ӷ��������ֻ��ͨ��linklist����lnode���͵�ָ�루��C++��ͬ��
//�ṹ���ڴ���ʱ�����ʼ�������Բ�����ֱ�Ӵ�����������ֱ��ʹ�ñ�����ָ��
typedef int status;
//�õ������е�i��Ԫ��
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

//�������в���Ԫ��
status list_insert(linklist &l,int i,int e)
//linklist &l �����ô��� �������޸����������
//linklist l ��ֵ���� ������l��һ������ �����޸�����
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
    //�ȴӱ��ڵ����Ľڵ����
    return 1;
}

//ɾ�������е�Ԫ��
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
    //һ��Ҫ�ͷŴ洢�ռ�
    return 1;
}

//β�巨����������Ҫp��q����ָ����������������Ķ�̬�仯��
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
//ͷ�巨��������(ֻ��Ҫʹ��һ��p�����������Ķ�̬�仯)
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

//�����������ϲ���һ�������
void mergelist(linklist &la,linklist &lb,linklist &lc)
{
    linklist x,y,z;
    x=la->next;
    y=lb->next;
    lc=z=la;
    //�˴���Ϊ�˽�Լ�ռ䣬��la,lb�ϲ���la��
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
       //��lb�ͷ��Խ�Լ�ռ�
    }




}



int main()

{
   linklist x;
headlist(x);


         }
