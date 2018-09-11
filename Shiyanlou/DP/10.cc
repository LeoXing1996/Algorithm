#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int longestIncreasingSubsequence(vector<int> &nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);

        for(int i=1; i<nums.size(); ++i){
            for(int j=0; j<i; ++j){
                if(nums[i]>nums[j]) dp[j] = max(dp[i], dp[j+1]);
            }
        }
        int res = 1;
        for(int i=1; i<nums.size(); ++i)
            res = max(res, dp[i]);
        return res;
    }
};

int main(){

}