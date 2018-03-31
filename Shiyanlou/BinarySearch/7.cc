#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        if(nums.empty())
            return false;
        if(*nums.begin()==target||*(nums.end()-1)==target)
            return true;
        int lb = 0;
        int hb = nums.size()-1;
        int mid;
        while(nums[hb]==nums[hb-1])
            --hb;
        while(nums[lb]==nums[lb+1])
            ++lb;
        if(nums[0]<target){
            while(lb+1<hb){
                mid = lb + (hb-lb)/2;
                if(nums[mid]==target) return true;
                if(nums[mid]>target){
                    //找到最小的hb
                    hb = mid;
                    while(nums[hb]==nums[hb-1])
                        --hb;
                }else if(nums[mid]<target && nums[mid]<nums[lb]){
                    hb = mid;
                    while(nums[hb]==nums[hb-1])
                        --hb;
                }else{
                    lb = mid;
                    while(nums[lb]==nums[lb+1])
                        ++lb;
                }
            }
        }else{
            while(lb+1<hb){
                mid = lb + (hb-lb)/2;
                if(nums[mid]==target) return true;
                if(nums[mid]<target){
                    lb = mid;
                    while(nums[lb]==nums[lb+1])
                        ++lb;
                } else if(nums[mid]>target && nums[mid]>nums[hb]){
                    lb = mid;
                    while(nums[lb]==nums[lb+1])
                        ++lb;
                } else{
                    hb = mid;
                    while(nums[hb-1]==nums[hb])
                        --hb;
                }
            }
        }
        return false;
    }
};

int main(){
    vector<int>nums = {1,1,1,0,1,1};
    Solution sol;
    if(sol.search(nums, 0))
        cout << "true" << endl;
    else    
        cout << "false" << endl;
    return 0;
}