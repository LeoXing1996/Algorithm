#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        vector<int>::iterator i = nums.end()-1;
        while(i > nums.begin() && *(i-1) <= *i)
            --i;
        
        if(i == nums.begin()) {
            reverse(nums.begin(), nums.end());
            return nums;
        } else --i;

        vector<int>::iterator j = nums.end()-1;
        while(*j >= *i) --j;
        iter_swap(i, j);
        reverse(i+1, nums.end());
        return nums;
    }
};

int main(){}