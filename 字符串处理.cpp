#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main() {
    int n = 0;
    char words[1005];
    while (scanf("%d",&n)!=EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", words);
            int k = 0;
            scanf("%d",&k);
            int index = 0, result = 0,sameWords=1;
            while (words[index] != '\0') {
                if(words[index]==words[index+1]){
                    ++sameWords;
                } else{
                    int add=sameWords-k+1;
                    if(add>0){
                        result+=add;
                    }
                    sameWords=1;
                }
                ++index;
            }
            printf("%d\n",result);
        }
    }
    return 0;
}
