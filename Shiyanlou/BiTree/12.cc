#include<iostream>
#include<vector>
#include"BiTree.h"
using namespace std;

class Solution{
private:
    TreeNode * findRoot(vector<int> &inorder, int in_s, int in_e, vector<int> &postorder, int po_s, int po_e){
        if(in_s == in_e) return new TreeNode(inorder[in_s]);

        TreeNode * root = new TreeNode(postorder[po_e]);
        // no left 
        if(inorder[in_s] == postorder[po_e])
            root->right = findRoot(inorder, in_s+1, in_e, postorder, po_s, po_e-1);
        // no right
        else if(inorder[in_e] == postorder[po_e])
            root->left = findRoot(inorder, in_s, in_e-1, postorder, po_s, po_e-1);
        // buildTree
        else {
            int root_i;
            for(int i=in_s; i<in_e; ++i) 
                if(inorder[i]==postorder[po_e]) {
                    root_i = i;
                    break;
                }        
            int left_p = root_i - in_s + po_s - 1;
            root->left = findRoot(inorder, in_s, root_i-1, postorder, po_s, left_p);
            root->right = findRoot(inorder, root_i+1, in_e, postorder, left_p+1, po_e-1);
        }
        return root;
    }
public:
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        if(size==0) return NULL;

        TreeNode * root = findRoot(inorder, 0, size-1, postorder, 0, size-1);
        return root;
    }
};

int main(){
    vector<int> in = {1,2,3};
    vector<int> post = {1,3,2};
    Solution sol;
    TreeNode* root = sol.buildTree(in, post);
    return 0;
}