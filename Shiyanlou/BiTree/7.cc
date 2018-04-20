#include<iostream>
#include<stack>
#include<limits.h>
#include"BiTree.h"

using namespace std;

class Solution{
public:
    int maxPathSum(TreeNode * root) {
        if(!root) return 0;
        
        return getSum(root).local_max;
    }
private:
    typedef struct{
        int node_max;
        int local_max;
    } Node;

    Node getSum(TreeNode * root){
        Node node;
        if(!root) {
            node = {0, INT_MIN};
            return node;
        }
        Node l_node = getSum(root->left);
        Node r_node = getSum(root->right);

        int node_max = max(l_node.node_max, r_node.node_max) + root->val;
        node_max = max(node_max, 0);
        node.node_max = node_max;

        int local_max = max(l_node.local_max, r_node.local_max);
        local_max = max(local_max, l_node.node_max + r_node.node_max + root->val);
        node.local_max = local_max;

        return node;
    }
};

int main(){return 0;}