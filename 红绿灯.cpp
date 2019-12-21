#include<bits/stdc++.h>
using namespace std;

int realTime(long long input,int time,int k,int r,int y,int g)
{
    int t;
    if(k==1)
    t = (input+r-time)%(r+y+g);
    if(k==2)
    t = (input+y-time+g+r)%(r+y+g);
    if(k==3)
    t = (input+g-time+r)%(r+y+g);

    if(t<r)
    return r-t;
    if(r<=t<r+g)
    return 0;
    if(r+g<=t<r+y+g) return 2*r+y+g-t;
}
int main()
{
    int r,y,g;
    int n;
    cin>>r>>y>>g;
    cin>>n;
    long long out = 0;
    while(n--)
    {
        int k,t;
        cin>>k>>t;
        if(k==0) out+=t;
        if(k==1||k==2||k==3) out+=realTime(out,t,k,r,y,g);
    }
    cout<<out;
    return 0;
}
