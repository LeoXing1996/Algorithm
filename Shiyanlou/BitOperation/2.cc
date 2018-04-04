#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int singleNumII(vector<int>&nums){
        if(nums.empty())
            return -1;
        int res = 0, bit_i_sum = 0;
        for(int i=0; i!= 8*(sizeof(int)); ++i){
            bit_i_sum = 0;
            for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
                bit_i_sum += ((*iter >> i) & 1);
            }
            res |= (bit_i_sum % 3) << i;
        }
        return res;
    }
};

int main(){
    vector<int>nums = {34,34,12,12,35,12,34};
    Solution sol;
    cout << sol.singleNumII(nums) << endl;
    return 0;
}