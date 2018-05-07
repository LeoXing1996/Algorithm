#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        TreeNode * res = helper(nums, 0, nums.size()-1);
        return res;
    }
private:
    TreeNode * helper(vector<int>nums, int start, int end){
        if(start > end) return NULL;
        int mid = (end - start)/2 + start;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid-1);
        root->right = helper(nums, mid+1, end);
        return root;
    }
};

int main(){}