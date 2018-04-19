#include<iostream>
#include<stack>
#include"BiTree.h"

using namespace std;

class Solution{
public:
    isBalance(TreeNode * root){
        int depth = getDepth(root);

        if(depth == -1) return false;
        else return true;
    }
private:
    int getDepth(TreeNode * root){
        if(!root) return 0;
        
        int l_depth = getDepth(root->left);
        int r_depth = getDepth(root->right);
        
        if(l_depth == -1 || r_depth == -1 || l_depth - r_depth > 1 || r_depth - l_depth > 1) return -1;
        
        int depth = l_depth > r_depth ? l_depth + 1 : r_depth + 1;
        return depth;
    }
};

int main(){
    return 0;
}