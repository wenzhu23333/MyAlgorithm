#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<iostream>
using namespace std;
# define max_vertex_num 21
typedef int infotype ;
typedef int vertextype ;
typedef int status;
typedef struct arcnode{
int adjvex;
struct arcnode *next;
infotype info;
}arcnode;
typedef struct vnode{
vertextype data;
arcnode *firstarc;
}vnode,adjlist[max_vertex_num];
typedef struct{
adjlist vertices;
int vexnum,arcnum;
int kind;
}algraph;

//�ڽӱ������
void creat_adjacency_list(algraph &g)
{
    arcnode *p,*q;
    printf("������ͼ�Ķ����������20�����ͻ���:");
    scanf("%d",&g.vexnum);
    scanf("%d",&g.arcnum);
    printf("������ͼ�����ࣨ1������ͼ��2������ͼ:");
    scanf("%d",&g.kind);
    printf("����������Ϣ\n");
    int i=1;
    for(i=1;i<=g.vexnum;i++)
    {
        printf("�������");
        printf("%d",i);
        printf("���������Ϣ��");
        scanf("%d",&g.vertices[i].data);
         g.vertices[i].firstarc=(arcnode*)malloc(sizeof(arcnode));
         g.vertices[i].firstarc->next=NULL;
    }

   printf("�����뻡����Ϣ\n");
   for(i=1;i<=g.arcnum;i++)
   {

        printf("�������");
        printf("%d",i);
        printf("��������Ϣ��");
        printf("�������������Ȩֵ:");
        int weight;
        scanf("%d",&weight);
        int i,j;//���뻡ͷ�뻡β
        printf("�����뻡ͷ��");
        scanf("%d",&i);
        if(g.kind==2)
        {
            printf("�����뻡β��");
            scanf("%d",&j);
        }
        if(g.vertices[i].firstarc==NULL)
        {
            p=(arcnode*)malloc(sizeof(arcnode));
            g.vertices[i].firstarc->next=p;
            p->next=NULL;
        }
        else
        {
            q=g.vertices[i].firstarc;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            p=(arcnode*)malloc(sizeof(arcnode));
            q->next=p;
            p->next=NULL;
        }
        p->adjvex=j;
        p->info=weight;

if(g.kind==2)
{
  if(g.vertices[j].firstarc==NULL)
          {
            p=(arcnode*)malloc(sizeof(arcnode));
            g.vertices[j].firstarc->next=p;
            p->next=NULL;
        }
        else
        {
            q=g.vertices[j].firstarc;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            p=(arcnode*)malloc(sizeof(arcnode));
            q->next=p;
            p->next=NULL;
        }
        p->adjvex=i;
        p->info=weight;
}
   }
}


//�������������DFS��
int visited[21];//0�ŵ�Ԫ��ʹ��
status (*visitFunc)(int v,algraph g);//ȫ�ֱ���������������������ָ��

void DFS(algraph g,int v)//�ӵ�v����������ݹ�������ȱ���ͼg
{
    arcnode *p=g.vertices[v].firstarc->next;//p��Ϊindex���һ���
    visited[v]=1;
    printf("%d",g.vertices[v].data);
    while(p)
    {
        if(!visited[p->adjvex]) DFS(g,p->adjvex);
       p=p->next;
    }
}
//��ͼG��������ȱ���
void DFSTraverse(algraph g,status (*visit)(int v,algraph g))
{
    int v=1;
    visitFunc=visit;
    for(v=1;v<=g.vexnum;++v) visited[v]=0;
    for(v=1;v<=g.vexnum;++v) if(!visited[v])
        DFS(g,v);
}
status visit(int v,algraph g)
{

    printf("%d",g.vertices[v].data);
}

//��ͼG��������ȱ���

void BFSTraverse(algraph g,status (*visit)(int v,algraph g))
{
    int v=1;
    int u;
    stack<int> st;
    for(v;v<=g.vexnum;v++) visited[v]=0;
    for(v=1;v<=g.vexnum;v++)
        if(!visited[v])
    {
        st.push(v);
        visit(v,g);
        while(!st.empty())
       {
       u=st.top();
       st.pop();
       arcnode *p=g.vertices[u].firstarc->next;
       while(!p)
        {
            if(!visited[p->adjvex])
            {
                visit(p->adjvex,g);
                st.push(p->adjvex);
                visited[p->adjvex]=1;
                p=p->next;
            }
        }
       }
    }
}

//PRIM�㷨������С������
//����m�ź�n�Žڵ�Ļ���Ȩֵ�����������򷵻�INF
#define INF 9999;
int getweight(algraph g,int m,int n)
{
    if(m==n) return 0;
    arcnode *p;
    p=g.vertices[m].firstarc->next;
    while(p->adjvex!=n&&p)
    {
        p=p->next;
    }
    if(!p)
        return INF;
    return p->info;
}


void PRIM(algraph g,int v)//�ӵ�v���ڵ���Ѱ����С������
{
    int i;//����ѭ��
    int index=1;
    int tmp;//��¼Ȩֵ
int weight[max_vertex_num];
int node[max_vertex_num];
node[index++]=v;
for(i=1;i<=g.vexnum;i++)
weight[i]=getweight(g,v,i);
for(i=1;i<=g.vexnum;i++)
{
    if(v==i) continue;
    int min_=INF;
    int j=1;
    int k=1;
    cout<<"��С�������ı�Ȩֵ���£�"<<endl;
while(j<=g.vexnum)
     {

        if((weight[j]!=0)&&(weight[j]<min_))
           {
               min_=weight[j];
               k=j;

           }
           j++;
    }

    cout<<min_;
    cout<<endl;
    node[index++]=k;
    weight[k]=0;
    for(j=1;j<=g.vexnum;j++)
    {
        tmp=getweight(g,k,j);
        if(weight[j]!=0&&tmp<weight[j])
            weight[j]=tmp;
    }
}
cout<<"��С�������Ľڵ����£�";
for(i=1;i<=g.vexnum;i++)
    cout<<node[i];

}

//���·���㷨
void Dijkstra(algraph g,int v)
{
    int dis[max_vertex_num];///��¼��v�㵽���������·����ֵ
    int book[max_vertex_num];
    int i=1;
    int j=1;
    int u=0;
    for(i;i<=g.vexnum;i++)
        book[i]=0;
    book[v]=1;
    for(i=1;i<=g.vexnum;i++)
        dis[i]=getweight(g,v,i);
    for(i=1;i<=g.vexnum-1;i++)
        {
            int min=INF;
            for(j=1;j<=g.vexnum;j++)
            {
                if(book[j]==0&&dis[j]<min)
                {
                    min=dis[j];
                    u=j;
                }
            }

        book[u]=1;
        arcnode *p=g.vertices[u].firstarc->next;
        while(!p)
            {
                if(dis[u]+p->info<dis[p->adjvex])
                dis[p->adjvex]=dis[u]+p->info;

                p=p->next;
            }
        }
        for(i=1;i<=g.vexnum;i++)
           {
               cout<<dis[i];
           }
}


int main()
{
algraph g;
creat_adjacency_list(g);
/*arcnode *p;
p=g.vertices[1].firstarc;
int i=0;
while(p->next!=NULL)
{
i++;
p=p->next;
}
printf("%d",i);
*/
DFSTraverse(g,visit);
cout<<endl;
BFSTraverse(g,visit);
cout<<endl;
//PRIM(g,1);
//cout<<"���·��:";
//Dijkstra(g,1);
}
