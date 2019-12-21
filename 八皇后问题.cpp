#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define max 4
using namespace std;
int queen[max], sum=0; /* maxΪ����������� */

void show() /* ������лʺ������ */
{
    int i;
    for(i = 0; i < max; i++)
         cout<<queen[i]<<" ";
    sum++;
}

bool isPLACE(int n) /* ��鵱ǰ���ܷ���ûʺ� */
{
    int i;
    for(i = 0; i < n; i++) /* �����źͶԽ������Ƿ���Է��ûʺ� */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
        {
            return false;
        }
    }
    return true;
}

void NQUEENS(int n) /* ���ݳ��Իʺ�λ��,nΪ������ */
{
    int i;
    for(i = 0; i < max; i++)
    {
        queen[n] = i; /* ���ʺ�ڵ���ǰѭ������λ�� */
        if(isPLACE(n))
        {
            if(n == max - 1)
            {
                show();
                cout<<endl;/* ���ȫ���ںã���������лʺ������ */
            }
            else
            {
                NQUEENS(n + 1); /* ��������ڷ���һ���ʺ� */
            }
        }
    }
}

int main()
{
    NQUEENS(0); /* �Ӻ�����Ϊ0��ʼ���γ��� */
    cout<<"һ���У�"<<sum<<"�ַŷ�"<<endl;;
    system("pause");
    return 0;
}


















/*#include<bits/stdc++.h>
using namespace std;
#define N 4

int x[N];
//�жϵ�ǰλ���Ƿ���Է���һ���ʺ�
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
               if(k<n) {   k=k+1;  x[k]=-1;  } //�����µ�һ�У��ٴӵ�0�п�ʼ
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

