#include<bits/stdc++.h>
#include <strstream>

using namespace std;
class point
{
public:
    double i;
    double j;
};
bool cmp(point a, point b)       //比较两点之间的x值
{
    return a.i < b.i;
}
double min(double a, double b)
{
    return a < b ? a : b;
}
double dist(point x,point y)
{
    return sqrt((x.i-y.i)*(x.i-y.i)+(x.j-y.j)*(x.j-y.j));
}
void generateEx(int k)//产生样例点，并保存在 point.csv 文件中
{
    ofstream point("point.csv");//打开 point.csv 文件
    for(int i=0;i<k;i++)
    point<<rand()+rand() / double(RAND_MAX)<<","<<rand()+rand() / double(RAND_MAX)<<endl;
    cout<<"生成成功！样例点已保存到文件"<<endl;
}

int *tmp=new int[10000];
//最近点对
double closed_pair(point* a,int left,int right,point &point_1,point &point_2)
{
   double d = INFINITY;
    if((right-left+1)==1)
    {
         return d;
    }
    else if((right-left+1)==2)
    {
        point_1 = a[left];
        point_2 = a[right];
        return dist(a[left],a[right]);
    }
    else if((right-left+1)>2)
    {
        int i1,j1,k=0,mid;
        mid=(right+left)>>1;
        point n1,n2;
        double d1 = closed_pair(a,left,mid,n1,n2);
        double d2 = closed_pair(a,mid+1,right,point_1,point_2);
        if(d1<d2)
        {
             point_1=n1;
             point_2=n2;
        }
         d = min(d1,d2);
        for(i1=0;i1<(right-left+1);i1++)
            if(fabs(a[i1].i-a[mid].i)<=d)
                tmp[k++]=i1;
       //sort(tmp,tmp+k);
        for(i1=0;i1<k;i1++)
            for(j1=i1+1;j1<k&&fabs(a[tmp[j1]].j-a[tmp[i1]].j)<d;j1++)
        {
            double d3=dist(a[tmp[i1]],a[tmp[j1]]);
            if(d>d3)
             {
                d=d3;
                point_1=a[tmp[i1]];
                point_2=a[tmp[j1]];
             }
        }
       return d;
    }
}

//蛮力法

double brute_force(point *a,int left,int right,point &point_1,point &point_2)
{
    double d=INFINITY;
    for(int i=left;i<=right;i++)
        for(int j=i+1;j<=right;j++)
           if(dist(a[i],a[j])<d)
           {
            d=dist(a[i],a[j]);
            point_1=a[i];
            point_2=a[j];
           }
           return d;
}
double convertStringToDouble(const string &s)
{
    double val;
    strstream ss;
    ss << s;
    ss >> val;
    return val;
}
//将string转换为double类型
int main()
{
 clock_t startTime,endTime;
//cout<<"请输入随机生成的点数：";
int k = 5000 ;
//cin>>k;
//generateEx(k);
point *Ex = new point[k];
ifstream in("point.csv");
string line;
if(in.is_open())
{
    for(int i2=0;i2<k;i2++)
    {
        getline(in,line);
        istringstream sin(line);
        string field;
       getline(sin, field, ',');
       Ex[i2].i=convertStringToDouble(field);
       getline(sin, field, ',');
       Ex[i2].j=convertStringToDouble(field);
    }
}
sort(Ex,Ex+k,cmp);
point Target1,Target2,Target3,Target4;
cout<<endl;

cout<<"使用Brute Force的方法："<<endl;
cout<<"最短距离为：";
 startTime = clock();
cout<<brute_force(Ex,0,k-1,Target1,Target2)<<endl;
 endTime = clock();
cout<<"对应的点对为：";
cout<<"("<<Target1.i<<","<<Target1.j<<")"<<"和";
cout<<"("<<Target2.i<<","<<Target2.j<<")"<<endl;
cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
cout<<endl;

cout<<"使用Divide and conquer的方法："<<endl;
cout<<"最短距离为：";
 startTime = clock();
cout<<closed_pair(Ex,0,k-1,Target3,Target4)<<endl;
 endTime = clock();
cout<<"对应的点对为：";
cout<<"("<<Target3.i<<","<<Target3.j<<")"<<"和";
cout<<"("<<Target4.i<<","<<Target4.j<<")"<<endl;
cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}
