#include<bits/stdc++.h>
using namespace std;

bool isChou(int n)
{
    int i = n;
    while(true)
    {
        if(i==1)
        return 1;
        else if(i%2!=0&&i%3!=0&&i%5!=0&&i%7!=0)
        return 0;

        if(!(i%2)) i=i/2;
        if(!(i%3)) i=i/3;
        if(!(i%5)) i=i/5;
        if(!(i%7)) i=i/7;
    }

}

int main()
{

    int i = 0;
    int n = 1;
    while(i!=5842)
    {
        if(isChou(n))
           {
               cout<<n<<" ";
               i++;
           }
        n++;

    }
    return 0;
}
