#include<stdio.h>
#include<stdlib.h>
#define maxsize 1000
typedef struct
{
    int data;
    int cur;
}component,slinklist[maxsize];

//静态链表定位某个data

int slinklist_locate(slinklist s,int e)
{
    //在静态链表s中查找元素e
    //返回次序 否则返回0
    int i;
    i=s[0].cur;
    while(i&&s[i].data!=e)
    {i=s[i].cur;}
    return i;
}

//找到静态链表的末尾
int seek_tail(slinklist s)
{
    int i;
    for(i=0;i++;i<maxsize)
      {
          if(0==s[i].cur)
           return i;
      }
}

//静态链表的输出
void print_slinklist(slinklist s)
{
    int i;
    for(i=0;i++;i<maxsize)
      {printf("%d %d /n",s[i].data,s[i].data);
      system("pause");
      }
}

//静态链表的插入
int slink_insert(slinklist s,int e,int p)
{
    int i,m;
   i=slinklist_locate(s, e);
   m=seek_tail(s);
   s[i].cur=m+1;
   s[m+1].data=p;
   s[m+1].cur=s[i+1].cur;
}

int main()
{
    slinklist x;
    int i=0;
    for(i=0;i<3;i++)
    {
      scanf("%d",&(x[i].data));
      (x[i].cur)=i+1;
    }
slink_insert(x,3,10);
print_slinklist(x);

}
