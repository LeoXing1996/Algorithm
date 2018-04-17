#include<iostream>
#include<vector>
#include"BiTree.h"

using namespace std;

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> res;
        if(!root) return res;
        
        vector<TreeNode *> Stack;
        TreeNode * curr = root;
        pushLeft(Stack, curr);
        while(!Stack.empty()){
            TreeNode * Left = Stack.back();
            Stack.pop_back();
            res.push_back(Left->val);
            pushLeft(Stack, Left->right);
        }
        return res;
    }
private:
    void pushLeft(vector<TreeNode*> & Stack, TreeNode * curr){
        while(curr){
            Stack.push_back(curr);
            curr = curr->left;
        }
    }
};

int main(){}