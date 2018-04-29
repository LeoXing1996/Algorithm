#include<iostream>
#include"BiTree.h"
using namespace std;

class Solution{
public:
    bool isSubTree(TreeeNode * t1, TreeNode * t2){
        if(!t2) return true;
        if(!t1) return false;

        return idential(t1,t2) || isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
    }

private:
    bool idential(TreeNode * t1, TreeNode * t2){
        if(!t2) return true;
        if(!t1) return false;
        if(t1->val != t2->val) return false;

        return idential(t1->left, t2->left) && idential(t1->right, t2->right);
    }
};

int main(){}