#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return res;

        tar = target;
        vector<int> list;
        dfs(res, list, candidates, 0);
        return res;
    }
private:
    int tar;
    void dfs(vector<vector<int>> & res, vector<int> & list, const vector<int> & nums, int pos){
        int sum = Sum(list);
        if(sum > tar)
            return ;
        else if(sum == tar){
            res.push_back(list);
            return ;
        } else {
            for(int i=pos; i<nums.size(); ++i){
                if(i>=pos+1 && nums[i]==nums[i-1]) continue;
                list.push_back(nums[i]);
                dfs(res, list, nums, i+1);
                list.pop_back();
            }
        }

    }
    int Sum(const vector<int> & list){
        int sum = 0;
        for(vector<int>::const_iterator iter=list.begin(); iter!=list.end(); ++iter)
            sum += *iter;
        return sum;
    }
};

int main(){}