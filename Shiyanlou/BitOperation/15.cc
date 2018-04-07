#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: The majority number that occurs more than 1/3
     */
    int majorityNumber(vector<int>& nums) {
        int c1=0, c2=0;
        int k1 = -1, k2 = -1;
        for(auto n:nums){
            if(c1==0 || k1==n){k1 = n; ++c1;}
            else if (c2==0 || k2==n){k2 = n; ++c2;}
            else{--c1; --c2;}
        }
        c1=0; c2=0;
        for(auto n:nums){
            if(n==k1) ++c1;
            if(n==k2) ++c2;
        }
        return c1>c2 ? k1 : k2;
    }
};

int main(){
    vector<int> nums = {7,7,7,1,1,1,7,2,2,2};
    Solution sol;
    cout << sol.majorityNumber(nums);
    return 0;
}