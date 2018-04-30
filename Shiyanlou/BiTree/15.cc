#include<iostream>
#include<string>
#include"BiTree.h"

using namespace std;

class Solution{
public:
    string serialize(TreeNode * root) {
        if(!root) return NULL;
        string res = to_string(root->val);
        
        buildStr(res, root);
        return res;
    }
    TreeNode * deserialize(string &data) {
        if(data.empty() || data[0] == '#') return NULL;
        int nodeVal = stoi(data);
        popNode(data);
        TreeNode * root = new TreeNode(nodeVal);
        buildTree(data, root);
        return root;
    }
private:
    void popNode(string & data){
        // 找到字符串中的第一个逗号，将逗号连通前面的都删掉
        int pos;
        int size = data.size();
        for(pos=0; pos<size; ++pos)
            if(data[pos]==',') break;
        // if(pos == size) data = NULL;
        // string 不可以设为NULL
        if(pos == size) data = "";
        else data = data.substr(pos+1);
    }

    void buildStr(string & data, TreeNode * root){
        // 生成左子树结果
        if(root->left) {
            data += to_string(root->left->val);
            buildStr(data, root->left);
        } else data += '#';
        if(root->right){
            data += to_string(root->right->val);
            buildStr(data, root->right);
        } else data += '#';
    }

    void buildTree(string & data, TreeNode* &root){
        if(data.empty()) return ;
        // 左子树生成
        if(data[0] != '#'){
            int nodeVal = stoi(data);
            root->left = new TreeNode(nodeVal);
            popNode(data);
            buildTree(data, root->left);
        } else if (data[0] == '#') popNode(data);
        if(data.empty()) return ;
        // 右子树生成
        if(data[0] != '#'){
            int nodeVal = stoi(data);
            root->right = new TreeNode(nodeVal);
            popNode(data);
            buildTree(data, root->right);
        } else if(data[0] == '#') popNode(data);
    }
};

int main(){

}