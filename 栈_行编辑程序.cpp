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

//���û����ָոս����һ���ַ��Ǵ��ʱ���ɲ���һ���˸����#�����Ա�ʾǰһ���ַ���Ч��������ֵ�ǰ���������
//���϶�����Բ��ȣ����������һ���˸����@�����Ա�ʾ��ǰ���е��ַ�����Ч��

void linedit()
{
    sqstack s;
    initstack(s);
    char ch,*p;
    char c;
    ch=getchar();
    while(ch!=EOF)
//��ô������ڼ�������ʱ������EOF�أ� ��ͬ��ϵͳ������ͬ��
//linuxϵͳ�£�������س����к�Ŀ���λ�ã��� ctrl+d (�Ȱ�ctrl�������ţ��ٰ�d����
//windowsϵͳ�£�������س����к�Ŀ���λ�ã��� ctrl+z���ٻس�ȷ��
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

          //�������break ������д�Ĵ��벻���ơ�
    }
   ch=getchar();
}

    //��ջ�е����ݴ���
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

