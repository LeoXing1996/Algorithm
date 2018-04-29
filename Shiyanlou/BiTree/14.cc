#include<iostream>
#include<vector>
#include<deque>
#include"BiTree.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool isLeft = false;
        deque<TreeNode *> leftLevel;
        deque<TreeNode *> rightLevel;
        vector<vector<int>> res;
        if(!root) return res;

        leftLevel.push_back(root);
        while((!isLeft && !leftLevel.empty()) || (isLeft && !rightLevel.empty())){
            vector<int> level;
            if(isLeft){
                int size = rightLevel.size();
                for(int i=0; i<size; ++i){
                    TreeNode * temp = rightLevel.front();
                    rightLevel.pop_front();
                    level.push_back(temp->val);
                    if(temp->right) leftLevel.push_front(temp->right);
                    if(temp->left) leftLevel.push_front(temp->left);
                    rightLevel.clear();
                }
            } else {
                int size = leftLevel.size();
                for(int i=0; i<size; ++i){
                    TreeNode * temp = leftLevel.front();
                    leftLevel.pop_front();
                    level.push_back(temp->val);
                    if(temp->left) rightLevel.push_front(temp->left);
                    if(temp->right) rightLevel.push_front(temp->right);
                    leftLevel.clear();
                }
            }
            isLeft = !isLeft;
            res.push_back(level);
        }
        return res;
    }
};

int main(){
    TreeNode * root = new TreeNode(1);
    TreeNode * l = new TreeNode(2);
    TreeNode * r = new TreeNode(3);
    TreeNode * rl = new TreeNode(4);
    TreeNode * rr = new TreeNode(5);
    
    
    root->left = l;
    root->right = r;

    r->left = rl;
    r->right = rr;

    Solution sol;
    vector<vector<int>> res =  sol.zigzagLevelOrder(root);
    for(vector<vector<int>> :: iterator iter = res.begin(); iter != res.end(); ++iter){
        for(vector<int>::iterator iter_ = (*iter).begin(); iter_ !=(*iter).end(); ++iter_)
            cout<< *iter_ << ' ';
        cout << endl;
    }
}