#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stud_node
{
    int num,score;
    char name[20];
    struct stud_node *next;
}stud_node;
stud_node *create()
{
    int num,score;
    char name;
    int size=sizeof(stud_node);
    stud_node *head,*p,*tail;
    head=tail=NULL;
    printf("Input number,name and score:\n");
    scanf("%d%s%d",&num,name,&score);
    while(num!=0)
    {
        p=(stud_node*)malloc(size);
        p->next=NULL;
        p->num=num;
        strcpy(p->name,name);
        p->score=score;
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            tail->next=p;
        }
        tail=p;
        printf("Input number,name and score:\n");
        scanf("%d%s%d",&num,name,&score);
    }
    return head;
}
int main()
{
    stud_node * head;
    head=create();
    printf("%d",head);
}
