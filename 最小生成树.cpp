// Prim算法实现（采用邻接表存储）
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAX 100
#define Infinity 65535
typedef  int WeiType;
using namespace std;
struct edgeNode
{
 int no; //边端的序号
 char info; //边端的名称
 WeiType weight; //边的权值
 struct edgeNode * next; //下一个
};
struct vexNode
{
 char info;  //节点名称
 struct edgeNode *link; //与之相连的端点
};
//存储节点信息
vexNode adjlist[MAX];
//访问标志
bool visited[MAX];
//lowcost[j]存储从开始节点到节点j的最小花费
WeiType lowcost[MAX];
//parent[j]表示节点j的前驱节点
int parent[MAX];
//建立邻接表存储
void createGraph(vexNode *adjlist,const int n,const int e,const int v0)
{

 int i;
 for(i=1;i<=n;i++)
 {
  cout<<"请输入节点"<<i<<"的名称：";
  cin>>adjlist[i].info;
  adjlist[i].link = NULL;
  //初始化
  visited[i] = false;
  lowcost[i] = Infinity;
  parent[i] = v0;
 }
 edgeNode *p1,*p2;
   int v1,v2;
   WeiType weight;
 for(i=1;i<=e;i++)
 {
  cout<<"请输入边"<<i<<"的二端的节点序号：";
  cin>>v1>>v2;
  cout<<"此边的权值：";
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
 cout<<"请输入案例的个数：";
 cin>>cases;
 while(cases--)
 {
  int n,e;
  cout<<"请输入节点数：";
  cin>>n;
  cout<<"请输入边数：";
  cin>>e;
  cout<<"请输入从哪一个节点开始：";
  int v;
  cin>>v;
  int i,j;
  //最小生成树的权值总和
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
  cout<<"最小生成树的边集为："<<endl;
  for(i=1;i<=n;i++)
   if(i!=v)
    cout<<"("<<adjlist[parent[i]].info<<","<<adjlist[i].info<<")"<<" ";
  cout<<endl;
  cout<<"最小生成树的权值为："<<sum<<endl;
 }
 system("pause");
 return 0;
}
