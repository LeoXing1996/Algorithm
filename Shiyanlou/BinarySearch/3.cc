#include<iostream>
#include<vector>

using namespace std;

class Solution{
private:
    int tar;
    int lowerBound(vector<int>&nums){
        int lb = -1;
        int hb = nums.size();
        int mid = lb + (hb - lb)/2;
        while(lb+1<hb){
            if(nums[mid]>=tar) hb = mid;
            else lb = mid;
            mid = lb + (hb - lb)/2;
        }
        return hb;
    }

    int higherBound(vector<int>&nums, int low){
        int lb = low;
        int hb = nums.size();
        int mid = lb + (hb - lb)/2;
        while(lb+1<hb){
            if(nums[mid]<=tar) lb = mid;
            else hb = mid;
            mid = lb + (hb - lb)/2;
        }
        return lb;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int> res;
        if(nums.size()==0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        tar = target;
        int lb = lowerBound(nums);
        if(nums[lb]!=nums[lb+1]){
            res.push_back(lb);
            res.push_back(lb);
            return res;
        }
        int hb = higherBound(nums,lb);
        res.push_back(lb);
        res.push_back(hb);
        return res;
    }
};

int main(){
    int a[6] = {1,2,2,2,3,3};
    vector<int> nums(a,a+5);
    int target = 2;
    Solution sol;
    vector<int>res = sol.searchRange(nums, target);
    cout << res[0] << ' ' << res[1] << endl;

    return 0;
}