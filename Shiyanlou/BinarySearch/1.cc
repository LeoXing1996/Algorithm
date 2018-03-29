#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int searchInsertPosition(vector<int>&nums, int target){
        if(nums.size()==0)
            return 0;
        int lb = 0;
        int hb = nums.size()-1;
        int pos = (lb+hb)/2;
        while(lb<=hb){
            if(nums[pos]==target)
                return pos;
            if(nums[pos]>target){
                hb = pos - 1;
            }else{
                lb = pos + 1;
            }
            pos = (lb+hb)/2;
        }
        if(nums[pos]<target)
            return pos+1;
        else
            return pos;
    }
};

int main(){
    int a[4] = {1,3,5,6};
    vector<int> nums(a, a+4);
    Solution sol;
    int res = sol.searchInsertPosition(nums, 2);
    cout << res << endl;
    return 0;
}