#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {

       if(vin.size() == 0) return NULL;
        int root = pre[0];
        int p;
        for(int i = 0;i<vin.size();i++)
        {
            if(vin[i] == root)
            {
                p = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(root);
        vector<int> pre1,vin1;
        vector<int> pre2,vin2;
        for(int i = 0;i<p;i++)
        {
            pre1.push_back(pre[i+1]);
            vin1.push_back(vin[i]);
        }
        for(int i = p+1;i<vin.size();i++)
        {
            pre2.push_back(pre[i]);
            vin2.push_back(vin[i]);
        }
        node->left = reConstructBinaryTree(pre1,vin1);
        node->right = reConstructBinaryTree(pre2,vin2);
        return node;
    }
};
void Pre(TreeNode* t)
{
    if(t)
    {
        cout<<t->val;
        Pre(t->left);
        Pre(t->right);
    }
}
int main()
{
    vector<int> pre;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(8);
    vector<int> vin;
    vin.push_back(4);
    vin.push_back(7);
    vin.push_back(2);
    vin.push_back(1);
    vin.push_back(5);
    vin.push_back(3);
    vin.push_back(8);
    vin.push_back(6);
    Solution* s = new Solution();
    Pre(s->reConstructBinaryTree(pre,vin));
    return 0;
}
