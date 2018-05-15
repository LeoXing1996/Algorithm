#include<iostream>
#include"BiTree.h"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
private:
    int dfs(TreeNode * root){
        if(!root) return 0;
        int rightDepth = dfs(root->right);
        int leftDepth = dfs(root->left);
        int currDepth;
        if(rightDepth == 0) currDepth = leftDepth+1;
        else if(leftDepth == 0) currDepth = rightDepth+1;
        else currDepth = (rightDepth < leftDepth ? rightDepth : leftDepth)+1;
        return currDepth;
    }
};

int main(){}