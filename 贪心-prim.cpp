#include <stdio.h>
#include <limits.h>
#include<bits/stdc++.h>
#define V 7
//这个函数用来查找剩余点到达已经查到的集合的最小的边的点的编号
int minKey(int key[], bool mstSet[])
{
   int min = INT_MAX, min_index;
   //min_index用来记录最短节点的编号
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
   return min_index;
}
int printMST(int parent[], int n, int graph[V][V])
{
   printf("边   权重\n");
   for (int i = 1; i < V; i++)
   printf("%d - %d    %d \n", parent[i]+1, i+1, graph[i][parent[i]]);
}
//此函数用于输出最小生成树
void primMST(int graph[V][V])
{
     int parent[V];
     int key[V];
     bool mstSet[V];
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
     key[0] = 0;
     parent[0] = -1;
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST(parent, V, graph);
}

int main()
{
    int graph[V][V];
   memset(graph, 0, sizeof(graph));
   graph[0][1] = 2;graph[0][3] = 1;graph[0][2] = 4;
   graph[1][0] = 2;graph[1][3] = 3;graph[1][4] = 10;
   graph[2][0] = 4;graph[2][3] = 2;graph[2][5] = 5;
   graph[3][0] = 1;graph[3][1] = 3;graph[3][2] = 2;graph[3][4] = 7;graph[3][5] = 8;graph[3][6] = 4;
   graph[4][1] = 10;graph[4][3] = 7;graph[4][6] = 6;
   graph[5][2] = 5;graph[5][3] = 8;graph[5][6] = 1;
   graph[6][3] = 4;graph[6][4] = 6;graph[6][5] = 1;
    primMST(graph);
    return 0;
}
