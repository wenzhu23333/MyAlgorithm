#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
      int i = 0,j = array[0].size()-1;
        while(true){
          if(target == array[i][j]) return true;
          if(target<array[i][j]) j--;
          if(target>array[i][j]) i++;
      }
        return false;
    }
};
int main()
{
    new Solution();
    return 0 ;
}
