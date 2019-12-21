// Prim�㷨ʵ�֣������ڽӱ�洢��
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX 100
#define Infinity 65535
typedef  int WeiType;
using namespace std;
struct edgeNode
{
 int no; //�߶˵����
 char info; //�߶˵�����
 WeiType weight; //�ߵ�Ȩֵ
 struct edgeNode * next; //��һ��
};
struct vexNode
{
 char info;  //�ڵ�����
 struct edgeNode *link; //��֮�����Ķ˵�
};
//�洢�ڵ���Ϣ
vexNode adjlist[MAX];
//���ʱ�־
bool visited[MAX];
//lowcost[j]�洢�ӿ�ʼ�ڵ㵽�ڵ�j����С����
WeiType lowcost[MAX];
//parent[j]��ʾ�ڵ�j��ǰ���ڵ�
int parent[MAX];
//�����ڽӱ�洢
void createGraph(vexNode *adjlist,const int n,const int e,const int v0)
{

 int i;
 for(i=1;i<=n;i++)
 {
  cout<<"������ڵ�"<<i<<"�����ƣ�";
  cin>>adjlist[i].info;
  adjlist[i].link = NULL;
  //��ʼ��
  visited[i] = false;
  lowcost[i] = Infinity;
  parent[i] = v0;
 }
 edgeNode *p1,*p2;
   int v1,v2;
   WeiType weight;
 for(i=1;i<=e;i++)
 {
  cout<<"�������"<<i<<"�Ķ��˵Ľڵ���ţ�";
  cin>>v1>>v2;
  cout<<"�˱ߵ�Ȩֵ��";
  cin>>weight;
  p1 = (edgeNode*)malloc(sizeof(edgeNode));
  p2 = (edgeNode*)malloc(sizeof(edgeNode));
  p1->no = v1;
  p1->weight = weight;
  p1->info = adjlist[v1].info;
  p1->next = adjlist[v2].link;
  adjlist[v2].link = p1;
  p2->no = v2;
  p2->weight = weight;
  p2->info = adjlist[v2].info;
  p2->next = adjlist[v1].link;
  adjlist[v1].link = p2;
 }
}

int main()
{
 int cases;
 cout<<"�����밸���ĸ�����";
 cin>>cases;
 while(cases--)
 {
  int n,e;
  cout<<"������ڵ�����";
  cin>>n;
  cout<<"�����������";
  cin>>e;
  cout<<"���������һ���ڵ㿪ʼ��";
  int v;
  cin>>v;
  int i,j;
  //��С��������Ȩֵ�ܺ�
  WeiType sum = 0;
  createGraph(adjlist,n,e,v);
  edgeNode *p,*q;
  p = adjlist[v].link;
  visited[v] = true;
  while(p!=NULL)
  {
   lowcost[p->no] = p->weight;
   p = p->next;
  }
  WeiType minCost;
  for(i=1;i<n;i++)
  {
   minCost = Infinity;
   int k;
   for(j=1;j<=n;j++)
   {
    if(minCost>lowcost[j]&&!visited[j])
    {
     minCost = lowcost[j];
     k = j;
    }
   }
   sum += minCost;
   visited[k] = true;
   q = adjlist[k].link;
   while(q != NULL)
   {
    if(!visited[q->no]&&q->weight<lowcost[q->no])
    {
     lowcost[q->no] = q->weight;
     parent[q->no] = k;
    }
    q = q->next;
   }
  }
  cout<<"��С�������ı߼�Ϊ��"<<endl;
  for(i=1;i<=n;i++)
   if(i!=v)
    cout<<"("<<adjlist[parent[i]].info<<","<<adjlist[i].info<<")"<<" ";
  cout<<endl;
  cout<<"��С��������ȨֵΪ��"<<sum<<endl;
 }
 system("pause");
 return 0;
}
