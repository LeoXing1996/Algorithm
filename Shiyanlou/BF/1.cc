#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        
        vector<int> list;
        sort(nums.begin(), nums.end());
        dfs(list, res, nums, 0);
        return res;
    }
private:
    void dfs(vector<int> &list, vector<vector<int>>& res, vector<int>& nums, int pos){
        res.push_back(list);

        for(int i=pos; i<nums.size(); ++i){
            list.push_back(nums[i]);
            dfs(list, res, nums, i+1);
            list.pop_back();
        }
    }
    
};

int main(){}