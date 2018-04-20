#include<iostream>
#include"BiTree.h"
using namespace std;
class Solution{
private:
    typedef struct{
        int node_depth;
        int local_depth;
    }Node_;

    Node_ getDepth(TreeNode * root){
        Node_ node;
        if(!root){
            node = {0,0};
            return node;
        }
        
        Node_ L_node = getDepth(root->left);
        Node_ R_node = getDepth(root->right);
        
        int node_depth = max(L_node.node_depth, R_node.node_depth)+1;
        node.node_depth = node_depth;
        
        int local_depth = max(L_node.local_depth, R_node.local_depth);
        local_depth = max(L_node.node_depth+R_node.node_depth+1, local_depth);
        node.local_depth = local_depth;
        return node;
    }
public:
    int diameter(TreeNode* node){
        if(!node) return 0;
        Node_ node_ = getDepth(node);
        return node_.local_depth;   
    }
};

int main(){return 0;}