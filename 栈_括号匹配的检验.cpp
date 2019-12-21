#define stack_init_size 100
#define stackincrement 10
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

typedef struct {
    char *base;
    char *top;
int stacksize;
}sqstack;
typedef int status;



//构造一个空栈
status initstack(sqstack &s)
{
    s.base=(char *)malloc(stack_init_size*sizeof(char));
    s.top=s.base;
    s.stacksize=stack_init_size;
    return 1;
}
//销毁栈
status destroystack(sqstack &s)
{
    free(s.base);
    s.top=NULL;
    s.base=NULL;
    return 1;
}
//置空栈
status clearstack(sqstack &s)
{
    s.top=s.base;
    return 1;
}
//判断栈是否为空
status stackempty(sqstack s)
{
    return (s.top==s.base)?1:0;
}
//返回栈的长度
int stacklength(sqstack s)
{
    return s.top-s.base;
}
//返回栈顶的元素
char gettop(sqstack s)
{
    if(!stackempty(s))
    {
    return *(s.top-1);

    }
    else
    return 0;
}
//插入元素e为新的栈顶元素
status push(sqstack &s,char e)
{
    if(s.top-s.base>=s.stacksize)//
     {
         s.base=(char *)realloc(s.base,(s.stacksize+stackincrement)*sizeof(char));
    //realloc则对malloc申请的内存进行大小的调整.
    if(!s.base)
        exit(1);
    s.top=s.base+s.stacksize;//top需要重新确定位置,因为realloc函数的现存数据会被拷贝至新的位置
    s.stacksize+=stackincrement;
     }
    *(s.top)=e;
    s.top++;
    return 1;

}

status pop(sqstack &s,char &e)
{
    if(s.top==s.base)
        return 0;
    s.top--;
    e=*(s.top);
    return 1;
}

status visit(char e)
{
   // printf("%d",e);
    return 1;
}

status stacktraverse(sqstack &s ,status (*visit)(char))
{

    while(s.base<s.top)
    {
        visit(*(s.base));//visit(*S.base++);  也可
        s.base++;
    }
    return 1;

}

//括号的匹配函数

status matching(char *e)
{
    sqstack s;
    initstack(s);
    int i=0,state=1;

//state主要用来处理只有右括号的情况，如果栈是空的，而读取时存在右括号，这样的状态需要记录下来，说明右括号多了，直接返回0状态。

    char a;
    while(e[i]!='\0')
    {
        switch(e[i])
        {

    case '(':
       {
           push(s,e[i]);
           i++;
           break;
       }
    case ')':
        {
            if(!stackempty(s)&&(gettop(s)=='('))
            {
                pop(s,a);
                i++;
            }
            else
            {
                state=0;
            }
            break;
        }

    }
    if(state==0)
        break;
    }

    if(stackempty(s)&&state)
        return 1;
    else
        return 0;
}
//判断时全部用单引号，赋值时全部用双引号
int main()
{
    char e[4]="()";
    printf("%d",matching(e));
}
