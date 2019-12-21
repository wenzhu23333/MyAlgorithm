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



//����һ����ջ
status initstack(sqstack &s)
{
    s.base=(int *)malloc(stack_init_size*sizeof(int));
    s.top=s.base;
    s.stacksize=stack_init_size;
    return 1;
}
//����ջ
status destroystack(sqstack &s)
{
    free(s.base);
    s.top=NULL;
    s.base=NULL;
    return 1;
}
//�ÿ�ջ
status clearstack(sqstack &s)
{
    s.top=s.base;
    return 1;
}
//�ж�ջ�Ƿ�Ϊ��
status stackempty(sqstack s)
{
    return (s.top==s.base)?1:0;
}
//����ջ�ĳ���
int stacklength(sqstack s)
{
    return s.top-s.base;
}
//����ջ����Ԫ��
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
//����Ԫ��eΪ�µ�ջ��Ԫ��
status push(sqstack &s,int e)
{
    if(s.top-s.base>=s.stacksize)//
     {
         s.base=(int *)realloc(s.base,(s.stacksize+stackincrement)*sizeof(int));
    //realloc���malloc������ڴ���д�С�ĵ���.
    if(!s.base)
        exit(1);
    s.top=s.base+s.stacksize;//top��Ҫ����ȷ��λ��,��Ϊrealloc�������ִ����ݻᱻ�������µ�λ��
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
        visit(*(s.base));//visit(*S.base++);  Ҳ��
        s.base++;
    }
    return 1;

}

//ջʵ������ת�� ʮ����ת�˽���
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

//����ƥ��ļ���




int main()
{
  /*  sqstack s;
    initstack(s);
    push(s,2);
printf("%d",stackempty(s));
*/
conversion();
}
