#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define list_init_size 100
#define listincrement 10
using namespace std;
typedef int status;
typedef int elemtype;

typedef struct
{
elemtype *elem;
int length;
int listsize;
}sqlist;



//建立一个新的线性表（顺序表示）
status initlist(sqlist &l)
{
    l.elem=(elemtype*)malloc(list_init_size*sizeof(elemtype));
    if(!l.elem)
        exit(0);
    l.length=0;
    l.listsize=list_init_size;
    return 1;
}

status creat_list(sqlist &l,int n)
{
    if(n>100)
    {
        l.elem=(elemtype*)realloc(l.elem,(list_init_size+n)*sizeof(elemtype));
        for(int i=0;i<n;i++)
            cin>>l.elem[i];
        l.length=n;
            return 1;
    }
    else
    {
        for(int i=0;i<n;i++)
            cin>>l.elem[i];
        l.length=n;
        return 1;
    }


}
//销毁一个链表

status destroylist(sqlist &l)
{
 free(l.elem);
 l.length=0;
 l.listsize=0;
 return 1;
}

//线性表数据的插入
//将x插入到第e个元素之后，
status insertlist(sqlist &l,int e,elemtype x)
{
    if(1+l.length>list_init_size)
    l.elem=(elemtype*)realloc(l.elem,(list_init_size+listincrement)*sizeof(elemtype));
    int i=l.length;
    for(i;i>e;i--)
    {
        l.elem[i]=l.elem[i-1];
    }
    l.elem[e]=x;
    return 1;
}

int main()
{
    sqlist l;
    int i;
    initlist(l);
    creat_list(l,4);
    insertlist(l,2,9);
    for(i=0;i<5;i++)
        cout<<l.elem[i];
}







