#include<iostream>
#include<limits>
#include"BiTree.h"

class Solution {
public:
    bool isValidBST(TreeNode * root) {
        if(!root) return true;

        return isBST(root->left, INT_MIN, root->val) && isBST(root->right, root->val, INT_MAX);
    }
private:
    bool isBST(TreeNode * root, int MIN, int MAX){
        if(!root) return true;
        if(root->val <=MIN || root->val >= MAX) return false;
        else return isBST(root->left, MIN, root->val) && isBST(root->right, root->val, MAX);
    }
};

int main(){}