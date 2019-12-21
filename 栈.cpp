#define stack_init_size 100
#define stackincrement 10
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int *base;
    int *top;
int stacksize;
}sqstack;
typedef int status;



//构造一个空栈
status initstack(sqstack &s)
{
    s.base=(int *)malloc(stack_init_size*sizeof(int));
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
status gettop(sqstack s,int &e)
{
    if(!stackempty(s))
    {
    e=*(s.top-1);
    return 1;
    }
    else
    return 0;
}
//插入元素e为新的栈顶元素
status push(sqstack &s,int e)
{
    if(s.top-s.base>=s.stacksize)//
     {
         s.base=(int *)realloc(s.base,(s.stacksize+stackincrement)*sizeof(int));
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

status pop(sqstack &s,int &e)
{
    if(s.top==s.base)
        return 0;
    s.top--;
    e=*(s.top);
    return 1;
}

status visit(int e)
{
    printf("%d",e);
    return 1;
}

status stacktraverse(sqstack &s ,status (*visit)(int))
{

    while(s.base<s.top)
    {
        visit(*(s.base));//visit(*S.base++);  也可
        s.base++;
    }
    return 1;

}

//栈实现数制转换 十进制转八进制
void conversion()
{
    sqstack s;
    int n,e;
    scanf("%d",&n);
    initstack(s);
    while(n)
    {
        push(s,n%8);
        n=n/8;
    }
    while(!stackempty(s))
    {
        pop(s,e);
        printf("%d",e);
    }

}

//括号匹配的检验




int main()
{
  /*  sqstack s;
    initstack(s);
    push(s,2);
printf("%d",stackempty(s));
*/
conversion();
}
