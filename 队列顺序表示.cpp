#include<stdio.h>
#include<stdlib.h>

#define maxsize 100
#define increasment 10;
typedef int Qelemtype;
typedef int status;
typedef struct
{
    Qelemtype* base;
    int front;
    int rear;
}squeue;

status initialsqueue(squeue &s)
{
    s.base=(Qelemtype*)malloc(maxsize*sizeof(Qelemtype));
    if(!s.base)
        return 0;
    s.front=s.rear=0;
    return 1;
}

//入队
status Ensqueue(squeue &s,Qelemtype e)
{
    if((s.rear+1)%maxsize==s.front)
       {
           printf("队列已满！");
           return 0;
       }
    s.base[s.rear]=e;
    s.rear=(s.rear+1)%maxsize;
    return 1;
}

//出队
status Desqueue(squeue &s,Qelemtype &e)
{
    if(s.front==s.rear)
        return 0;
    e=s.base[s.front];
    s.front=(s.front+1)%maxsize;
return 1;
}

void show(squeue s)
{
    while(s.front!=s.rear)

    {

        printf("%d",s.base[s.front]);
        s.front++;
    }
}


int main()
{
    squeue s;
    Qelemtype e;
    initialsqueue(s);
    Ensqueue(s,2);
    Ensqueue(s,3);
    Ensqueue(s,4);
    Ensqueue(s,5);
    show(s);
    printf("\n");
    Desqueue(s,e);
    printf("%d",e);
    printf("\n");
    show(s);



}

