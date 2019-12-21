#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin>>input;
    int i = input.size()-1;
    int count = 0;
    for(i = input.size()-1;(input[i]! = ' ')&&(i>=0);i--)
        count++;
    cout<<count;
    return 0;
}
