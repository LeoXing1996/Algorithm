#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int quickSort(vector<int>& nums,int start, int end){
        int piv = nums[start];
        while(start < end){
            while(nums[end]>=piv && start < end) --end;
            nums[start] = nums[end];
            while(nums[start]<=piv && start < end) ++start;
            nums[end] = nums[start];
        }
        nums[end] = piv;
        if(nums.size()%2==0){
            if(end == nums.size()/2-1)
                return end;
            else if(end >  nums.size()/2-1){
                return quickSort(nums, 0, end-1);
            }else
                return quickSort(nums, end+1, nums.size()-1);
        } else {
            if(end == nums.size()/2)
                return end;
            else if(end > nums.size()/2)
                return quickSort(nums, 0, end-1);
            else 
                return quickSort(nums, end+1, nums.size()-1);
        }
    }
    int quickSort2(vector<int>& nums, int start, int end, int tar){
        int piv = start;
        for(int i=start+1; i<=end; ++i){
            if(nums[i]<nums[start]){
                ++piv;
                int temp = nums[piv];
                nums[piv] = nums[i];
                nums[i] = temp;
            }
        }
        int temp = nums[piv];
        nums[piv] = nums[start];
        nums[start] = temp;
        if(piv==tar)
            return nums[piv];
        else if(piv < tar)
            return quickSort2(nums, piv+1, end, tar);
        else
            return quickSort2(nums, start, piv-1, tar);
    }
public:
    int median(vector<int>& nums){
        int r =  quickSort(nums, 0, nums.size()-1);
        return nums[r];
    }
    int media2(vector<int>& nums){
        int tar;
        if(nums.size()%2==0)
            tar = nums.size()/2-1;
        else    
            tar = nums.size()/2;
        int r = quickSort2(nums, 0, nums.size()-1, tar);
    }
};

int main(){
    int a[5] = {4,5,1,2,3};
    vector<int> nums(a, a+5);
    // int res = sol.median(nums);
    Solution sol; 
    int res = sol.media2(nums);
    cout << res << endl;
    return 0;
}