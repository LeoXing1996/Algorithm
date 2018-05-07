#include<iostream>
#include<vector>
#include"BiTree.h"
using namespace std;

class Solution {
public:
  
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
        vector<int> res;
        betterPreOrder(root, res, k1, k2);
        return res;
    }
private:
    void preOrderTraverse(TreeNode* root, vector<int>&res, int k1, int k2){
        if(!root) return;
        preOrderTraverse(root->left, res, k1, k2);
        if(root->val <=k2 && root->val >= k1) res.push_back(root->val);
        preOrderTraverse(root->right, res, k1, k2);
    }

    void betterPreOrder(TreeNode * root, vector<int>& res, int k1,int k2){
        if(!root) return;
        if(root->val >= k1) betterPreOrder(root->left, res, k1, k2);
        if(root->val <= k2 && root->val >= k1) res.push_back(root->val);
        if(root->val <= k2 ) betterPreOrder(root->right, res, k1, k2);
    }
};

int main(){}