#include<stdio.h>
#include<stdlib.h>
typedef int Qelemtype;
typedef int status;
struct snode
{
  Qelemtype data;
  snode* next;
};
typedef struct
{

    snode* front;
    snode* rear;
}squeue;

 status initialsqueue(squeue &s)
 {
    s.front=s.rear=(snode*)malloc(sizeof(snode));
    s.front->next=s.rear;
     return 1;
 }

 status Ensqueue(squeue &s,Qelemtype e)
 {
     snode* p;
     p=(snode*)malloc(sizeof(snode));
  if(!p)
  {
      return 0;
  }
     p->data=e;
     p->next=s.front;
     s.rear->next=p;
     s.rear=p;
     return 1;
 }
 status Desqueue(squeue &s,Qelemtype &e)
 {
     if(s.front==s.rear)
        return 0;
     e=s.front->next->data;
     snode* p=s.front->next;
     s.front->next=s.front->next->next;
     free(p);
     return 1;
 }

 void show(squeue s)
 {
     while(s.front!=s.rear)
     {
         s.front=s.front->next;
          printf("%d",s.front->data);
     }


 }

 int main()
 {
     squeue s;
     Qelemtype e;
     initialsqueue(s);
     Ensqueue(s,9);
     Ensqueue(s,4);
     Ensqueue(s,5);
     Ensqueue(s,6);
     show(s);
     printf("\n");
     Desqueue(s,e);
    printf("%d",e);
    printf("\n");
    show(s);
 }
