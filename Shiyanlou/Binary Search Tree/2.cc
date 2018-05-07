#include<iostream>
#include<limits.h>
#include"BiTree.h"

class Solution {
public:
    bool isValidBST(TreeNode * root) {
        if(!root) return true;

        // return isBST(root->left, INT_MIN, root->val) && isBST(root->right, root->val, INT_MAX);
        return isBST__(root->left, LLONG_MIN, root->val) && isBST__(root->right, root->val, LLONG_MAX);
    }
private:
    bool isBST(TreeNode * root, int MIN, int MAX){
        if(!root) return true;
        // 考虑到有边界结点取到 INT_MAX 或 INT_MIN 
        // 因此，需要人为对 INT_MIN 与 INT_MAX 进行判断
        // 当然 也可以将传递的边界的 int 改为 long long 参见 isBST__
        if(root->val <=MIN || root->val >= MAX) {
            bool isRight = root->val == INT_MAX && !(root->right);
            bool isLeft = root->val == INT_MIN && !(root->left);
            if(!isRight && !isLeft) return false;   
        }
        return isBST(root->left, MIN, root->val) && isBST(root->right, root->val, MAX);
    }

    bool isBST__(TreeNode * root, long long MIN, long long MAX){
        if(!root) return true;
        if(root->val <= MIN || root->val >= MAX) return false;
        
        return isBST__(root->left, MIN, root->val) && isBST__(root->right, root->val, MAX);
    }
};

int main(){
    TreeNode * root = new TreeNode(INT_MIN);
    root->right = new TreeNode(INT_MAX);
    Solution sol;
    std::cout << sol.isValidBST(root);
}