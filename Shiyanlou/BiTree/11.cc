#include<iostream>
#include<vector>
#include"BiTree.h"

using namespace std;

class Solution{
private:
    TreeNode * findRoot(vector<int> &preorder, int pre_s, int pre_e, 
                        vector<int> &inorder, int in_s, int in_e){
        
        // if(pre_s > pre_e) return NULL;
        if(pre_s == pre_e) return new TreeNode(preorder[pre_s]);
        
        // build root
        TreeNode * root = new TreeNode(preorder[pre_s]);        
        // no left tree
        if(preorder[pre_s]==inorder[in_s])
            root->right = findRoot(preorder, pre_s+1, pre_e, inorder, in_s+1, in_e);
        // no right tree
        else if(preorder[pre_s]==inorder[in_e])
            root->left = findRoot(preorder, pre_s+1, pre_e, inorder, in_s, in_e-1);
        else{
            int root_i;
            for(int i=in_s; i<in_e; ++i) 
                if(inorder[i]==preorder[pre_s]){
                    root_i = i;
                    break;
                }
            int right_p = root_i-in_s +  pre_s + 1;
            
            root->left = findRoot(preorder, pre_s+1, right_p-1, inorder, in_s, root_i-1);
            root->right = findRoot(preorder, right_p, pre_e, inorder, root_i+1,in_e);
        }
        return root;
    }
public:
    TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0) return NULL;
        
        int size = preorder.size();
        TreeNode * root = findRoot(preorder, 0, size-1, inorder, 0, size-1);
        return root;
    }
};

int main(){
    vector<int> pre = {17,18,19,20,21,22,23};
    vector<int> in = {19,18,17,23,22,21,20};
    Solution sol;
    TreeNode * root = sol.buildTree(pre, in);
    return 0;
}