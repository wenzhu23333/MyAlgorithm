#include<bits/stdc++.h>
using namespace std;

int Add(int num1, int num2)
    {
      vector<int> a(num1);
        vector<int> b(num2);
        a.insert(a.end(),b.begin(),b.end());
        return a.size();

    }
    int main()
    {
        cout<<Add(12312234,1312323423);
        return 0;
    }
