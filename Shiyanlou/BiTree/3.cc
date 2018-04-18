#include <iostream>
#include <vector>
#include "BiTree.h"

using namespace std;

class Solution{
public:
    vector <int> postorderTraversal(TreeNode * root){
        vector<int> res;
        if(!root) return res;
        vector <pair <TreeNode*, TreeNode *>> Stack;
        pushLeft(Stack, root);
        // Stack.push_back({root, root->right});
        while(!Stack.empty()){
            // 左子树进栈
            TreeNode * curr_root = Stack.back().first;
            // 检查末结点
            if(!(Stack.back().second)){
                res.push_back(Stack.back().first->val);
                Stack.pop_back();
            } else {
                TreeNode * right_root = Stack.back().second;
                // pair<<TreeNode*, TreeNode *>> temp = {Stack.back()->first, NULL};
                // Stack.pop_back();
                // Stack.push_back(temp);
                Stack.back().second = NULL;
                pushLeft(Stack, right_root); 
            }
        }
        return res;
    }
private:
    void pushLeft(vector <pair <TreeNode*, TreeNode *>> & Stack, TreeNode * root){
        while(root){
            Stack.push_back({root, root->right});
            root = root->left;
        }
    }
};

int main(){}