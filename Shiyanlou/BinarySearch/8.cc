#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.empty())
            return -1;
        if(*nums.begin()<*(nums.end()-1))
            return *nums.begin();
        int lb = 0;
        int hb = nums.size()-1;

        int mid;
        while(lb+1<hb){
            mid = lb + (hb - lb) / 2;
            if(nums[mid]<nums[mid-1]) return nums[mid];
            if(nums[mid]>nums[mid+1]) return nums[mid+1];
            if(nums[mid]<nums[lb]) hb = mid;
            if(nums[mid]>nums[hb]) lb = mid;
        }
        return nums[hb];
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution sol;
    cout << sol.findMin(nums) <<  endl; 
    return 0;
}