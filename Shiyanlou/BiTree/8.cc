#include<iostream>
#include<stack>
#include"BiTree.h"

using namespace std;

class Solution{
public: 
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
        tar1 = A;
        tar2 = B;
        stack<NodeInf> S;
        // S.push({&root, root.right, false, false});
        pushLeft(S, root);
        while(!S.empty()){
            // 元素顺序出栈 并修改 flag 
            // 如果某一结点两个flag 均为true return！！
            NodeInf curr = S.top();
            S.pop();
            if((curr.flag1 == true) && (curr.flag2 == true)) return curr.root;
            else if(curr.rLeaf) {
                S.push({curr.root, NULL, curr.flag1, curr.flag2});
                pushLeft(S, curr.rLeaf);
            } else {
                S.top().flag1 = (curr.flag1 || S.top().flag1);
                S.top().flag2 = (curr.flag2 || S.top().flag2);
            }
        }
        return NULL;
    }
private:
    typedef struct{
        TreeNode * root;
        TreeNode * rLeaf;
        bool flag1 = false;
        bool flag2 = false;
    } NodeInf;

    TreeNode * tar1;
    TreeNode * tar2;

    void pushLeft(stack<NodeInf>&S, TreeNode * root){
        while(root){
            if(root == tar1 && root == tar2) {
                S.push({root, NULL, true, true});
                return ;
            }
            else if(root == tar1) S.push({root, root->right, true, false});
            else if(root == tar2) S.push({root, root->right, false, true});
            else S.push({root, root->right, false, false});
            root =root->left;
        }
    }
};

int main(){}