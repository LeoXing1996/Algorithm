#include<iostream>
#include<vector>
#include<list>
#include"BiTree.h"

using namespace std;

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> res;
        if(!root) return res;

        LAYER Layer;
        Layer.push_back(root);
        while(!Layer.empty()){
            vector<int> _res;
            pushRes(Layer, _res);
            res.push_back(_res);
            nextLayer(Layer);
        }
        return res;
    }
private:
    typedef list<TreeNode *> LAYER;

    void nextLayer(LAYER &Layer){
        int size = Layer.size();
        for(int i=0; i<size; ++i){
            TreeNode * temp = Layer.front();
            Layer.pop_front();
            if(temp->left) Layer.push_back(temp->left);
            if(temp->right) Layer.push_back(temp->right);
        }
    }

    void pushRes(LAYER Layer, vector <int> &_res){
        for(LAYER::iterator iter = Layer.begin(); iter != Layer.end(); ++iter)
            _res.push_back((*iter)->val);
    }
};

// class Solution2{
// public:
//     vector<vector<int>> levelOrder(TreeNode * root) {

//     }
// };

int main(){

    return 0;
}