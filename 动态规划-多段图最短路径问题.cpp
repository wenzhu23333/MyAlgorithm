#include<bits/stdc++.h>
#define N 13
#define INF 9999
using namespace std;
int graph[N][N];
 void InitGraph()
 {
     memset(graph, -1, sizeof(graph));
     graph[1][2] = 9;graph[1][3] = 7;graph[1][4] = 3;graph[1][5] = 2;
     graph[2][6] = 4;graph[2][7] = 2;graph[2][8] = 1;
     graph[3][6] = 2;graph[3][7] = 7;
     graph[4][8] = 11;
     graph[5][7] = 11;graph[5][8] = 8;
     graph[6][9] = 6;graph[6][10] = 5;
     graph[7][9] = 4;graph[7][10] = 3;
     graph[8][10] = 5;graph[8][11] = 6;
     graph[9][12] = 4;
     graph[10][12] = 2;
     graph[11][12] = 5;
 }
int Output[N][N];
int cost[N]; //��¼ÿ���ڵ�����·������
int d[N]; //��¼ÿ���ڵ����·������һ���ڵ�
 void MultisstageGraph()
 {

  cost[12] = 0;
  for(int i = 11;i>0;i--)
  {
      int temp = INF;
      int nextNode = -1;
      for(int j = 1;j<N;j++)
      {

          if(graph[i][j]>0&&graph[i][j]+cost[j]<temp)
         {
             temp = graph[i][j]+cost[j];
             nextNode = j;
         }


      }
      cost[i] = temp;
      d[i] = nextNode;
  }

 }

 int main()
 {
     InitGraph();
     MultisstageGraph();
     for(int i = 1;i<N;i++)
       {
           cout<<"�ڵ�"<<i<<"���ڵ�12����̾��룺"<<cost[i];
           cout<<"  ��һ����"<<d[i]<<endl;
       }
 }
