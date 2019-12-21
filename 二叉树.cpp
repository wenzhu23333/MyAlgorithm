#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char telemtype;
typedef int status ;
typedef struct BiTnode
{
    telemtype data;
    struct BiTnode* lchild,* rchild;

}BiTnode,*bitree;

status creatbitree(bitree &t)
{
    char e;
    scanf("%c",&e);
    if(e=='#')
    {
            t=NULL;
    }
    else
    {
        t=(bitree)malloc(sizeof(BiTnode));
        t->data=e;
        creatbitree(t->lchild);
        creatbitree(t->rchild);
    }

}
//以下为遍历算法的递归形式
status preOrderTraverse(bitree t)
{
    if(!t)
        return 0;
    if(t)
    {
        printf("%c",t->data);
        preOrderTraverse(t->lchild);
        preOrderTraverse(t->rchild);
    }
}
status inOrderTraverse(bitree t)
{
    if(!t)
        return 0;
    if(t)
    {
        preOrderTraverse(t->lchild);
        printf("%c",t->data);
        preOrderTraverse(t->rchild);
    }

}
status postOrderTraverse(bitree t)
{
    if(!t)
        return 0;
    if(t)
    {
        preOrderTraverse(t->lchild);
        preOrderTraverse(t->rchild);
        printf("%c",t->data);
    }
}

//链栈

typedef bitree elemtype;
typedef int status;
 struct lnode
{

    elemtype data;
    lnode* next;
};
typedef struct
{
    lnode* top;
    int length;

}Stack;

void initialStack(Stack &l)
{
    l.top=NULL;
    l.length=0;
}

status stackempty(Stack l)
{
    return l.length>0?0:1;
}

status push(Stack &l,elemtype e)
{
    lnode* p=(lnode*)malloc(sizeof(lnode));
    p->data=e;
    p->next=l.top;
    l.top=p;
    l.length++;
    return 1;
}

status pop(Stack &l,elemtype &e)
{
    if(!l.top)
        return 0;
    e=l.top->data;
    lnode* q=l.top;
    l.top=l.top->next;
    free(q);
    l.length--;
    return 1;
}
void show(Stack l)
{
    lnode *p;
    p=l.top;
    while(p!=NULL)
    {
                printf("%d",p->data);
                p=p->next;
    }

}
void gettop(Stack l,elemtype &e)
{

    e=l.top->data;

}

//



//以下为遍历算法的非递归形式
status in(bitree t)
{
    if(!t) return 0;
    Stack s; initialStack(s);
    bitree p=t;
    while(p||!stackempty(s))
    {
        while(p)
        {
            push(s,p);
            p=p->lchild;
        }
        if(!stackempty(s))
        {
            pop(s,p);
            printf("%c",p->data);
            p=p->rchild;
        }
    }
}
status pre(bitree t)
{
     if(!t) return 0;
    Stack s; initialStack(s);
    bitree p=t;
    while(p||!stackempty(s))
    {
        while(p)
        {
            push(s,p);
            printf("%c",p->data);
            p=p->lchild;

        }
        if(!stackempty(s))
        {
            pop(s,p);
            p=p->rchild;
        }
    }
}
status post(bitree t)
{
  if(!t) return 0;
  Stack s; initialStack(s);
  bitree p=t;
  bitree pre=NULL;
  push(s,p);
  while(!stackempty(s))
  {
      gettop(s,p);
      if(p->lchild==NULL&&p->rchild==NULL||(pre!=NULL&&(p->lchild==pre||p->rchild==pre)))
      {
          printf("%c",p->data);
          pop(s,p);
          pre=p;
      }
      else
      {
          if(p->rchild) push(s,p->rchild);
          if(p->lchild) push(s,p->lchild);
      }
  }
}


//求二叉树的深度
int finddeep(bitree t)
{
    int deep=0;
    if(t)
    {
        int leftdeep=finddeep(t->lchild);
        int rightdeep=finddeep(t->rchild);
        deep=leftdeep>=rightdeep?leftdeep+1:rightdeep+1;
    }
    return deep;
}
//求二叉树的节点数
int findnum(bitree t)
{
    if(!t)
        return 0;
   return findnum(t->lchild)+findnum(t->rchild)+1;
}

//求二叉树的叶子节点数
int findleafnum(bitree t)
{
   /*其中的一种写法
    int num=0;

if(t)
   {
       if(!t->lchild&&!t->rchild)
        num++;
       else{
       num=findleafnum(t->lchild)+ findleafnum(t->rchild);
       }
   }

    return num;
    */

    int num=0;

    if(!t)
    return 0;

   else if(!t->lchild&&!t->rchild)
     return 1;

    return findleafnum(t->lchild)+ findleafnum(t->rchild);
}
//求二分支节点数
int findtwonum(bitree t)
{
    if(t->lchild&&t->rchild)
        return findtwonum(t->lchild)+findtwonum(t->rchild)+1;
    else return 0;
}

int main()
{
    bitree t;
   creatbitree(t);
   pre(t);
   printf("\n");
   in(t);
   printf("\n");
   post(t);
   printf("\n");
   printf("%d",finddeep(t));
   printf("\n");
printf("%d",findnum(t));
printf("\n");
printf("%d",findleafnum(t));
printf("\n");
printf("%d",findtwonum(t));
}
