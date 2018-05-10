#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;

        vector<int> list;
        dfs(res, list, nums);
        return res;
    }
private:
    void dfs(vector<vector<int>> & res, vector<int> & list, vector<int> & nums){
        if(list.size() == nums.size()) {
            res.push_back(list);
            return ;
        }

        for(int i=0; i<nums.size(); ++i){
            if(find(list.begin(), list.end(), nums[i]) != list.end()) continue;

            list.push_back(nums[i]);
            dfs(res, list, nums);
            list.pop_back();
        }
    }
};

int main(){}