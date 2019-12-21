#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int editDistDP(string str1, string str2, int m, int n)
{
    int dp[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i==0)
                dp[i][j] = j;
            else if (j==0)
                dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string str1 = "EXPONENTIALAPPLE";
    string str2 = "POLYNOMIALAPPLE";
    /*for(int i = 0;i<str1.length()+1;i++)
       {
           for(int j = 0 ;j<str2.length()+1;j++)
             cout <<editDistDP(str1, str2, i, j)<<"    ";
             cout<<endl;
       }*/
    ofstream outFile;
    outFile.open("EditDistanceOutput.csv", ios::out);
    for(int i=0;i<str1.length()+1;i++)
       {
         for(int j=0;j<str2.length()+1;j++)
         outFile<<editDistDP(str1, str2, i, j)<<",";
         outFile<<endl;
       }
    return 0;
}
