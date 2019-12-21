#include<bits/stdc++.h>
using namespace std;
bool isprime(long num)
{
 if(num<=3) return num>1;
 if(num%6!=1&&num%6!=5) return false;
 int s = sqrt(num);
    for (int i = 5; i <= s; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
int main()
{
    long x;
    cin>>x;
    long m = x;
    for(int i = 2;i<=m/2;i++)
    {
        while(!(x%i))
        {
            x/=i;
            if(isprime(i)) cout<<i<<" ";
        }
    }

    return 0;
}
