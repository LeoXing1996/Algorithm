#include<iostream>
#include<vector>
#include"BiTree.h"
using namespace std;
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        vector<TreeNode * > Stack;
        Stack.push_back(root);
        while(!Stack.empty()){
            TreeNode * temp = Stack.back();
            Stack.pop_back();
            res.push_back(temp->val);
            if(temp->right) Stack.push_back(temp->right);
            if(temp->left) Stack.push_back(temp->left);
        }
        return res;
    }
};

int main(){}