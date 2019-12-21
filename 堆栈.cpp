//链栈
#include<stdio.h>
#include<stdlib.h>



typedef int elemtype;
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
elemtype gettop(Stack l)
{
    return l.top->data;
}

int main()
{
    elemtype e;
    Stack s;
    initialStack(s);
    push(s,2);
    push(s,3);
    push(s,4);
     show(s);
    pop(s,e);
    printf("\n");
    printf("%d",e);
    printf("\n");
     show(s);
    printf("\n");
    printf("%d",gettop(s));
}
