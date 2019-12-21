#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	while (true)
	{
		int a, b;
		cin >> a >> b;
		int c = a + b;
		ostringstream o;
		o << c;
		string s = o.str();
		int j = 0;
		for(int i = 0;i<s.length();i++){
            if(s[i]=='-') {
                cout<<s[i];            }
            if(s[i]<='9'&&s[i]>='0') {
                    cout<<s[i];
                    j++;
            }
            if(j == 3&&i!=(s.length()-1)){
                j = 0;
                cout<<",";

            }
		}
	}
	return 0;
}
