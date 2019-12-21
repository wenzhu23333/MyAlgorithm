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



//����һ����ջ
status initstack(sqstack &s)
{
    s.base=(char *)malloc(stack_init_size*sizeof(char));
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
char gettop(sqstack s)
{
    if(!stackempty(s))
    {
    return *(s.top-1);

    }
    else
    return 0;
}
//����Ԫ��eΪ�µ�ջ��Ԫ��
status push(sqstack &s,char e)
{
    if(s.top-s.base>=s.stacksize)//
     {
         s.base=(char *)realloc(s.base,(s.stacksize+stackincrement)*sizeof(char));
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
        visit(*(s.base));//visit(*S.base++);  Ҳ��
        s.base++;
    }
    return 1;

}

//���ŵ�ƥ�亯��

status matching(char *e)
{
    sqstack s;
    initstack(s);
    int i=0,state=1;

//state��Ҫ��������ֻ�������ŵ���������ջ�ǿյģ�����ȡʱ���������ţ�������״̬��Ҫ��¼������˵�������Ŷ��ˣ�ֱ�ӷ���0״̬��

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
//�ж�ʱȫ���õ����ţ���ֵʱȫ����˫����
int main()
{
    char e[4]="()";
    printf("%d",matching(e));
}
