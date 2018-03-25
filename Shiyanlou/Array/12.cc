#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size()<=1)
            return nums.size();        
        for(vector<int>::iterator iter = nums.begin(); iter<nums.end()-1; ++iter){
            while(*iter == *(iter+1) && iter != nums.end()-1){
                iter = nums.erase(iter);
                --iter;
            }
        }
        return nums.size();
    }
};

int main(){
    int A[8] = {1,1,2,3,4,4,4,5};
    vector<int> nums(A,A+8);
    Solution sol;
    int res = sol.removeDuplicates(nums);
    cout << res << endl;
    return 0;
}