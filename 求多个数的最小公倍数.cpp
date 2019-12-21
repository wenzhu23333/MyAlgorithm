#include<bits/stdc++.h>
using namespace std;
int gcd(int m,int n)
{
    int t,q;
    if(m<n) {
           t=m;
           m=n;
           n=t;
            }
    while(n)
    {
     t=m%n;
     m=n;
     n=t;
    }
    return m;
}
int lcd(int* m,int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        m[i+1]=m[i]*m[i+1]/gcd(m[i],m[i+1]);
    }
    return m[n-1];
}
int main()
{
    int a[4]={1,2,16,7};
    cout<<lcd(a,4);

}
