#include<vector>
#include<iostream>
#include<algorithm>
#include"BiTree.h"
using namespace std;
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n<=0) return res;

        res = buildTree(1, n);
        return res;
    }
private:
    vector<TreeNode*> buildTree(int start, int end){
        vector<TreeNode *> res;
        if(start > end) res.push_back(NULL);
        else if(start == end) {
            TreeNode * root = new TreeNode (start);
            res.push_back(root);
        } else {
            for(int par=start; par<=end; ++par){
                vector<TreeNode * > lTree =  buildTree(start, par-1);
                vector<TreeNode * > rTree =  buildTree(par+1, end);
                for(vector<TreeNode *>::iterator itL = lTree.begin(); itL!=lTree.end(); ++itL){
                    for(vector<TreeNode*>::iterator itR = rTree.begin(); itR!=rTree.end(); ++itR){
                        TreeNode * root = new TreeNode(par);
                        root->left = *itL;
                        root->right = *itR;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<TreeNode * > res = sol.generateTrees(3);
    cout << res.size() << endl;
}