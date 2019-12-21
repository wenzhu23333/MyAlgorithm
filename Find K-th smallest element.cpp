    #include<bits/stdc++.h>
#include <fstream>
#include <fstream>
#include <iostream>
#include<windows.h>
using namespace std;
//find k-th smallest element based on quicksort
int partition(int *a,int p,int q)
{
    int i=p,j=q,s=a[p];
    int t;
    while(i<j)
    {
        while(i<j&&a[j]>s) j--;
        if(i<j) {a[i]=a[j];i++;}
        while(i<j&&a[i]<s) i++;
        if(i<j) {a[j]=a[i];j--;}
    }
    a[i]=s;
    return i;
}
int partition(int *a,int p,int q,int x)
{

 int i=p;int j=q;int s=x;
    int t=p;
    while(a[t]!=x)
        t++;
    t=a[p];
    a[p]=a[t];
    a[t]=t;
    while(i<j)
    {
        while(i<j&&a[j]>s) j--;
        if(i<j) {a[i]=a[j];i++;}
        while(i<j&&a[i]<s) i++;
        if(i<j) {a[j]=a[i];j--;}
    }
    a[i]=s;
    return i;
}
void quicksort(int *a,int p,int q)
{
    if(p<q)
    {

        int r=partition(a,p,q);
        quicksort(a,p,r-1);
        quicksort(a,r+1,q);
    }
}
int findelement(int *a,int p,int q,int k)
{
    if(p==q) return a[p];
    int r=partition(a,p,q);
    int j=r-p+1;
    if(j==k) return a[r];
    else
    if(j>k) return findelement(a,p,r-1,k);
    else return findelement(a,r+1,q,k-j);
}
//线性时间选择

int select(int *a,int p,int r,int k)
{
    if(p<r)
    {
        int *b=new int[r-p];
        int t=0;
        int i;
        for(i=p;i<r;i+=5)
        {
            //quicksort(a,i,i+4);
            b[t++]=findelement(a,i,min(i+5,r),(min(i+5,r)-i+1)/2);
           /* if(i+5>r)
                b[t++]=a[r+1];*/
        }
        int x=select(b,0,t-1,(t+1)/2);
        for(i=p;i<r;i++)
            if(x==a[i])
           {
               swap(a[i],a[p]);
               break;
           }
        int q=partition(a,p,r);
        int j=q-p+1;
        if(k==j)
            return a[q];
        else if(k>j) return select(a,q+1,r,k-j);
        return select(a,p,q-1,k);
    }
    if(p==r)
        if(k==1)
        return a[p];
        else return 0;
    else return -1;
   /* //if(n<75) return findelement(a,0,n-1,k);
    int t=n/5;
    int b[t];
    int i,j;
    for(i=0;i<n;i+=5)
    {
        quicksort(a,i,i+4);
        b[i/5]=a[i+2];
        if(i+5>n)
        {


        }
    }
    int x=select(b,t,t/2);
    int r=partition(a,0,n-1,x);
    int S1[r+1];
    int S2[n-r-1];
    for(i=0;i<r+1;i++)
     S1[i]=a[i];
    for(i=r+1;i<n;i++)
    S2[i]=a[i];
    if(k-1==r) return r;
    if(k-1<r) return select(S1,r+1,k);
    else return select(S2,n-r-1,k-r-1);*/

}
#define max_length 1000000
int main()
{



    clock_t startTime,endTime;
   // startTime = clock();
    int i=0;
    int t;
    char buf[80];
   // int a[1000000];
   int * a = new int[max_length];
    ofstream out("example.csv");
     if (out.is_open())
    {
        for(i=0;i<max_length;i++)
       {out<<rand()<<endl;}
        out.close();
     }
    cout<<"正在读取文件……"<<endl;
    ifstream in("example.csv");
     if(in.is_open())
     {for(i=0;i<max_length;i++)
       {
          in.getline(buf,80);
          a[i]=atoi(buf);
       }
       in.close();
     }
     //for(i=0;i<5000;i++)
       // cout<<a[i]<<endl;
    cout<<"读取成功！"<<endl;

    while(1)
    {
    cout<<"请输入您要寻找第几大的数字：";
    int input;
    cin>>input;
    cout<<"使用Median of Medians 算法："<<endl;
        startTime = clock();
    cout<<select(a,0,max_length-1,input)<<endl;
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    startTime = clock();
    cout<<"使用基于QS的算法："<<endl;
    cout<<findelement(a,0,max_length-1,input)<<endl;
    endTime = clock();
    cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;


     }
}
