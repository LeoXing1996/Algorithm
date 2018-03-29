#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int binarySearch(vector<int>&nums, int target){
        int lb = -1;
        int hb = nums.size();
        int mid = lb+(hb-lb)/2;
        if(hb==0)
            return -1;
        while(lb<hb){
            if(nums[mid]>=target) hb = mid;
            else lb = mid+1;
            mid = lb+(hb-lb)/2;
        }   
        if(nums[lb]==target)
            return lb;
        else
            return -1;
    }
};

int main(){
    int a[5] = {1,2,2,2,3};
    int target = 2;
    vector<int> nums(a, a+5);
    Solution sol;
    int res =  sol.binarySearch(nums, target);
    cout << res << endl;
    return 0;
}