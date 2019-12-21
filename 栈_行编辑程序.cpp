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

//当用户发现刚刚建入的一个字符是错的时，可补进一个退格符“#”，以表示前一个字符无效；如果发现当前键入的行内
//差错较多或难以补救，则可以输入一个退格符“@”，以表示当前行中的字符均无效。

void linedit()
{
    sqstack s;
    initstack(s);
    char ch,*p;
    char c;
    ch=getchar();
    while(ch!=EOF)
//那么，如何在键盘输入时，产生EOF呢？ 不同的系统方法不同：
//linux系统下，在输入回车换行后的空行位置，按 ctrl+d (先按ctrl键，不放，再按d键）
//windows系统下，在输入回车换行后的空行位置，按 ctrl+z，再回车确认
{
    while(ch!=EOF&&ch!='\n')
    {

       switch(ch)
    {

      case '#':
          {
               pop(s,c);
               break;
          }
      case '@':
    {
      clearstack(s);
      break;
      }

      default:
          {
              push(s,ch);
              break;

          }

          //必须加上break ，书上写的代码不完善。
    }
   ch=getchar();
}

    //将栈中的数据传出
    p=s.base;
    while(p!=s.top)
    {
        printf("%c",*p);
        ++p;
    }

    clearstack(s);
    if(ch!=EOF) ch = getchar();
}

destroystack(s);
}

int main()
{
    linedit();

}

