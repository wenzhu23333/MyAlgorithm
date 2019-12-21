#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n,L,t;
    cin>>n>>L>>t;
    int  a[n];
    int  direction[n];
    for(int i = 0;i<n;i++)
    {
       cin>>a[i];
       direction[i] = 1;
    }
    //sort(a,a+n);
    for(int i = 0;i<t;i++)
    {

       for(int j=0;j<n;j++)
       {
           a[j]+=direction[j];
       }
       for(int j=0;j<n;j++)
       {
           for(int k = j+1;k<n;k++)
           {
            if(a[j]==a[k])
             {
              direction[j] = -direction[j];
              direction[k] = -direction[k];
             }
           }
          if(a[j]==L)
          direction[j] = -1;
          if(a[j]==0)
          direction[j] = 1;
       }
    }
    for(int i =0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
