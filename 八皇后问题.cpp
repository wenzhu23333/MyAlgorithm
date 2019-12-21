#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define max 4
using namespace std;
int queen[max], sum=0; /* max为棋盘最大坐标 */

void show() /* 输出所有皇后的坐标 */
{
    int i;
    for(i = 0; i < max; i++)
         cout<<queen[i]<<" ";
    sum++;
}

bool isPLACE(int n) /* 检查当前列能否放置皇后 */
{
    int i;
    for(i = 0; i < n; i++) /* 检查横排和对角线上是否可以放置皇后 */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
        {
            return false;
        }
    }
    return true;
}

void NQUEENS(int n) /* 回溯尝试皇后位置,n为横坐标 */
{
    int i;
    for(i = 0; i < max; i++)
    {
        queen[n] = i; /* 将皇后摆到当前循环到的位置 */
        if(isPLACE(n))
        {
            if(n == max - 1)
            {
                show();
                cout<<endl;/* 如果全部摆好，则输出所有皇后的坐标 */
            }
            else
            {
                NQUEENS(n + 1); /* 否则继续摆放下一个皇后 */
            }
        }
    }
}

int main()
{
    NQUEENS(0); /* 从横坐标为0开始依次尝试 */
    cout<<"一共有："<<sum<<"种放法"<<endl;;
    system("pause");
    return 0;
}


















/*#include<bits/stdc++.h>
using namespace std;
#define N 4

int x[N];
//判断当前位置是否可以放置一个皇后
bool Place(int k)
{
    int i ;
    for(i = 0;i<k-1;i++)
        if(x[i] == x[k-1]||abs(x[i]-x[k-1])==abs(i-k+1))
       return false;
    return true;
}
NQueens()
{   int m = 0;
    int k;
    int n = N;
      k=0;
      x[k]= -1;
     while(k>=0)
     {   x[k]=x[k]+1;
          while((x[k]<n)&&(!Place(k)))
                x[k]=x[k]+1;
          if(x[k]<n)
          {
                  m++;
                  cout<<m<<endl;
               if(k<n) {   k=k+1;  x[k]=-1;  } //换到新的一行，再从第0列开始
              else
              {

                  for(int i = 0;i<N;i++)
                  cout<<i<<","<<x[i]<<endl;
                  cout<<endl;

              }
          }
          else k=k-1;
       }
}

int main()
{
    NQueens();
}
*/

