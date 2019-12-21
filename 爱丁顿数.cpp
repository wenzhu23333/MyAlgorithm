#include<bits/stdc++.h>
using namespace std;
bool cmp1(int a, int b) {
    return a > b;
}
int  main()
{
    int n;
    int out = 0;
    while(cin>>n)
    {
     int a[n],b[n];
     for(int i = 0;i<n;i++){
        cin>>a[i];
     }
     sort(a,a+n,cmp1);
     for(int i = 0;i<n;i++){
        if(a[i]>i) out++;
     }
     cout<<out<<endl;
    }
    return 0;
}
