#include<iostream>
#include<vector>
#include<stack>
#include"BiTree.h"

using namespace std;

class BSTIterator__bad {
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        preOrder(root);
        iter = TreeList.begin();
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        if(iter != TreeList.end()) return true;
        else return false;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode * res = *iter;
        ++iter;
        return res;
    }
private:
    vector<TreeNode*> TreeList;
    vector<TreeNode*>::iterator iter;
    void preOrder(TreeNode * root){
        if(!root) return ;
        preOrder(root->left);
        TreeList.push_back(root);
        preOrder(root->right);
    }
};

class BSTIterator{
public:
    BSTIterator(TreeNode * root) {
        _Push(root);
    }

    bool hasNext(){
        if(!s.empty()) return true;
        else return false;
    }
    TreeNode* next(){
        if(!hasNext()) return NULL;
        TreeNode * temp = s.top();
        s.pop();
        _Push(temp->right);
        return temp;
    }
private:
    TreeNode * curr;
    stack<TreeNode*> s;

    void _Push(TreeNode * curr){
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
    }
};

int main(){}