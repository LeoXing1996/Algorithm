#include<iostream>
// #include<vector>
#include"BiTree.h"

class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        // write your code here
        if(!node) return root;
        if(!root) return node;
        insert(root, node);
        return root;
    }
private:
    void insert(TreeNode * &root, TreeNode * &node){
        if(node->val <= root->val){
            if(root->left) insert(root->left, node);
            else {
                root->left = node;
                return;
            }
        } else {
            if(root->right) insert(root->right, node);
            else {
                root->right = node;
                return;
            }
        }
    }
};

int main(){

}