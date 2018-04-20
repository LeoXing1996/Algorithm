#include<iostream>
#include<list>
#include"BiTree.h"
using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        list<TreeNode * > S;
        S.push_back(root);
        while(!S.empty()){
            int Size = S.size();
            for(int i=0; i<Size; ++i) {
                TreeNode * curr = S.front();
                S.pop_front();
                TreeNode * temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;
                if(curr->left) S.push_back(curr->left);
                if(curr->right) S.push_back(curr->right);
            }
        }
        return root;
    }
};

int main(){}