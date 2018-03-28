#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    int help(vector<int>&nums, int start, int end, int n){
        int piv = start;
        for(int i=start+1; i<=end; ++i){
            if(nums[i]>nums[start]){
                ++piv;
                swap(nums[i], nums[piv]);
            }
        }
        swap(nums[start], nums[piv]);
        if(piv==n)
            return nums[piv];
        else if(piv > n)
            return help(nums, start, piv-1, n);
        else
            return help(nums, piv+1, end, n);
    }

public:
    int kthLargestElement(int n, vector<int>&nums){
        return help(nums, 0, nums.size()-1, n-1);
    }
};

int main(){
    int a[5] = {9,3,2,4,8};
    vector<int> nums(a, a+5);
    Solution sol;
    int res = sol.kthLargestElement(3, nums);
    cout << res;
    return 0;
}
