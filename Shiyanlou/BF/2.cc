#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;

        vector<int> list;
        sort(nums.begin(), nums.end());
        dfs(nums, list, res, 0, true);
        return res;
    }
private:
    void dfs(vector<int> & nums, vector<int> & list, vector<vector<int>> & res, int pos, bool isfirst){
        res.push_back(list);

        for(int i=pos; i<nums.size(); ++i){
            
            if(isfirst)
                isfirst = false;
            else 
                while(i<nums.size() && nums[i]!=nums[i-1]) ++i;
            
            list.push_back(nums[i]);
            dfs(nums, list, res, i+1, true);
            list.pop_back();
            
        }
    }
};

int main(){}