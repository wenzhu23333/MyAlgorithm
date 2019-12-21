#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> m;
    int x,y;
    while(n--)
    {
     cin>>x>>y;
     if(m.count(x))
     {
         m[x] = m[x]+y;
     }
     else m[x] = y;
    }
    map <int, int>::iterator iter;
    for(iter = m.begin();iter!=m.end();iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }

    return 0;
}
