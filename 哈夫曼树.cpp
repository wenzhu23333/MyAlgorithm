#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
unsigned int weight;
unsigned int parent,lchild,rchild;
}htnode,*huffmantree;

typedef char **huffmancode;
void select(huffmantree ht,int n,int &s1,int &s2)
{
    int i=0;
    htnode t;
    int m=0;
    for(i=1;i<=n;i++)
        if(ht[i].parent==0)
        {
            m=i;
            break;
        }
   for(i=1;i<=n;i++)
   {
       if(ht[i].parent==0)
        if(ht[i].weight<ht[m].weight)
       m=i;
   }
   s1=m;
    for(i=1;i<=n;i++)
    {
        if(ht[i].parent==0&&i!=s1)
        {
            m=i;
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(ht[i].parent==0&&i!=s1)
        if(ht[i].weight<ht[m].weight)
        m=i;
    }
    s2=m;
}
//½¨Á¢¹þ·òÂüÊ÷
void buildhuffmantree(huffmantree &ht,int *w,int n)
{
    int m,i,s1,s2;
    huffmantree p;
    if(n<1) return;
    m=2*n-1;
    ht=(huffmantree)malloc((m+1)*sizeof(htnode));
    p=ht;
    for(i=1;i<=n;++i)
    p[i]={w[i-1],0,0,0};
    for(;i<=m;++i)
    p[i]={0,0,0,0};
    for(i=n+1;i<=m;++i)
    {
        select(ht,i-1,s1,s2);
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;
    }
}

//ÇóÃ¿¸ö×Ö·ûµÄ¹þ·òÂü±àÂë
void huffmancoding(huffmantree &ht,huffmancode &hc,int n)
{
    int f,c,start,i;
    hc=(huffmancode)malloc((n+1)*sizeof(char*));
    char *cd;
cd=(char *)malloc(n*sizeof(char));
cd[n-1]='\0';
for(i=1;i<=n;++i)
{
    start=n-1;
    for(c=i,f=ht[i].parent;f!=0;c=f,f=ht[f].parent)
    if(ht[f].lchild==c) cd[--start]='0';
    else cd[--start]='1';
    hc[i]=(char *)malloc((n-start)*sizeof(char));
    strcpy(hc[i],&cd[start]);
}
free(cd);
}



int main()
{
int i;
int n=8;
int w[8]={1,1,1,1,1,1,2,2};
huffmancode hc;
huffmantree ht;
buildhuffmantree(ht,w,n);
huffmancoding(ht,hc,n);
for(int i=1;i<=n;i++)
printf("%s\n",hc[i]);

}
