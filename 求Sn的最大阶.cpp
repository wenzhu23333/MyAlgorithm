#include<bits/stdc++.h>
using namespace std;
set< multiset<int> > GetAllIntDivision(int n)
{
    set< multiset<int> > allDivision;
    if(1==n)
    {
        multiset<int> aa;
        aa.insert(1);
        allDivision.insert(aa);
    }
    else
    {
        set<multiset<int> > iniDivision = GetAllIntDivision(n-1);
        for(set<multiset<int> >::iterator iter = iniDivision.begin();iter != iniDivision.end();iter++)
        {
            //添加后缀项
            multiset<int> inimul;
            inimul = *iter;
            inimul.insert(1);
            allDivision.insert(inimul);
            //添加累加项
            /*inimul = *iter;*/
            for (multiset<int>::iterator it = (*iter).begin();it!=(*iter).end();++it)
            {
                multiset<int>::iterator iit = it;
                inimul = *iter;
                while((++iit)!=(*iter).end()&&(*it)==(*iit))
                {
                    iit = (++it);
                }
                inimul.erase(inimul.find(*it));
                inimul.insert((*it)+1);
                allDivision.insert(inimul);
            }
        }
    }
    return allDivision;
}
int gcd(int m,int n)
{
    int t;
    if(m<n) {t=m;m=n,n=t;}
    while(n)
    {
     t=m%n;
     m=n;
     n=t;
    }
    return m;
}
int lcd(int*m ,int n)
{
    int i;
    for(i=0;i<n-1;i++)
    m[i+1]=m[i]*m[i+1]/gcd(m[i],m[i+1]);
    return m[n-1];
}
int main()
{
    int n;
    cout<<"请输入Sn的n：";
    cin>>n;
    set<multiset<int> > allDivision;
    allDivision = GetAllIntDivision(n);
    //输出结果
    int i = 0;
    int max=0;
    int c;
    int* d;
    for(set<multiset<int> >::iterator iter = allDivision.begin();iter != allDivision.end();iter++)
    {
        int* a=new int[(*iter).size()];
        int* b=new int[(*iter).size()];
        int i=0;
       for(multiset<int>::iterator it=(*iter).begin();it!=(*iter).end();it++)
        {
            b[i]=*it;
            a[i]=*it;
            i++;
        }
        int t=lcd(a,(*iter).size());
        if(t>max)
        {
        max=t;
        d=b;
        c=(*iter).size();
        }
    }
    cout<<"Sn的最大阶为："<<max<<endl;
    cout<<"这种划分方式为:"<<n<<"=";
    for(i=0;i<c;i++)
    {
        if(i==c-1) {cout<<d[i]; break;}
        cout<<d[i]<<"+";
    }
    return 0;
}
