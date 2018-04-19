#include<iostream>
#include<stack>
#include"BiTree.h"

using namespace std;

class Solution{
public:
    int maxDepth(TreeNode * root) {
        if(!root) return 0;
        
        int depth = 1;
        stack<pair<TreeNode*, int>> S;
        S.push({root, 1});
        while(!S.empty()){
            TreeNode * curr = S.top().first;
            int d = S.top().second;
            S.pop();
            depth = d > depth ? d : depth ;
            if(curr->left) S.push({curr->left, d+1});
            if(curr->right) S.push({curr->right, d+1});
        }
        return depth;
    }
};

int main(){
    return 0;
}