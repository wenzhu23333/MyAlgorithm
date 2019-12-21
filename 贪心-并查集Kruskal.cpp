#include<bits/stdc++.h>
//使用并查集数据结构来实现克鲁斯卡尔算法
using namespace std;
//建立边的类，用来存储边
class Edge
{
    public:
    int beginNode,endNode,weight;
};
class Graph
{
    public:
    int NodeNum;
    int EdgeNum;
    Edge *edge;
};

Graph* createGraph(int nodenum,int edgenum)
{
    Graph* graph = new Graph();
    graph->NodeNum = nodenum;
    graph->EdgeNum = edgenum;

    graph->edge = new Edge[edgenum];
    return graph;
}
class subset
{
    public:
    int parent;
    int rank;
};

int find(subset subsets[],int i)
{
    if(subsets[i].parent!=i)
        subsets[i].parent = find(subsets,subsets[i].parent);
    return subsets[i].parent;
}
void Union(subset subsets[],int x,int y)
{
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);
    if(subsets[xroot].rank<subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank>subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
//根据权值来排列边的大小
bool  myComp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void KruskalMST(Graph* graph)
{
    int v = graph->NodeNum;
    Edge result[v];
    //ppt上面的X集合
    int e = 0;
    int i = 0;
    //第一步：将所有的边按照权重排序
    sort(graph->edge,graph->edge+graph->EdgeNum,myComp);
    //MakeSet的步骤，为每个顶点makeset造一个集合
    subset* subsets = new subset[v];
    //对每个集合进行初始化
    for(int j = 0;j<v;++j)
    {
        subsets[j].parent = j;
        subsets[j].rank = 0;
    }
    //下面开始克鲁斯卡尔算法
    while(e<v-1)
    {
        Edge next_edge = graph->edge[i++];
        int x = find(subsets,next_edge.beginNode);
        int y = find(subsets,next_edge.endNode);
        if(x!=y)
        {
            result[e++] = next_edge;
            Union(subsets,x,y);
        }

    }

    cout<<"下面是克鲁斯卡尔算法所找到的边及其权重："<<endl;
    for(int i = 0;i<e;++i)
    {
        //cout<<graph->edge[i].weight;
        cout<<result[i].beginNode+1<<" -- "<<result[i].endNode+1<<" == "<<result[i].weight<<endl;
    }

}
int main( )
{
    int nodenum = 7;
    int edgenum = 12;
    Graph* graph = createGraph(nodenum,edgenum);
    graph->edge[0].beginNode = 0;
    graph->edge[0].endNode = 1;
    graph->edge[0].weight = 2;

    graph->edge[1].beginNode = 0;
    graph->edge[1].endNode = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].beginNode = 0;
    graph->edge[2].endNode = 3;
    graph->edge[2].weight = 1;

    graph->edge[3].beginNode = 1;
    graph->edge[3].endNode = 3;
    graph->edge[3].weight = 3;

    graph->edge[4].beginNode = 1;
    graph->edge[4].endNode = 4;
    graph->edge[4].weight = 10;

    graph->edge[5].beginNode = 2;
    graph->edge[5].endNode = 3;
    graph->edge[5].weight = 2;

    graph->edge[6].beginNode = 2;
    graph->edge[6].endNode = 5;
    graph->edge[6].weight = 5;

    graph->edge[7].beginNode = 3;
    graph->edge[7].endNode = 5;
    graph->edge[7].weight = 8;

    graph->edge[8].beginNode = 3;
    graph->edge[8].endNode = 4;
    graph->edge[8].weight = 7;

    graph->edge[9].beginNode = 5;
    graph->edge[9].endNode = 6;
    graph->edge[9].weight = 1;

    graph->edge[10].beginNode = 3;
    graph->edge[10].endNode = 6;
    graph->edge[10].weight = 4;

    graph->edge[11].beginNode = 4;
    graph->edge[11].endNode = 6;
    graph->edge[11].weight = 6;

    KruskalMST(graph);


}



