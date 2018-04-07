#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int majorityNumber(vector<int>& nums){
        if(nums.empty()) return -1;
        int k = nums[0];
        int count = 0;
        for(int i=0; i<nums.size(); ++i){
            if(count==0) k = nums[i];
            if(nums[i]==k) ++count;
            else --count;
        }
    }
};

int main(){

    return 0;
}