#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> singleNumIII(vector<int>&nums){
        int x1x2 = 0;
        for(vector<int>::iterator iter = nums.begin(); iter!=nums.end(); ++iter){
            x1x2 ^= *iter;
        }
        int i=0;
        while((x1x2>>i & 1) == 0){
            ++i;

        }
        x1x2 = 1 << i;
        // x1x2 -> 0...010...0
        int x1 = 0, x2 = 0;
        // cout << "x1x2: "<< x1x2 << endl;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
            if((*iter & x1x2) ==0){
                x2 ^= *iter;
                // cout << "*iter: " << *iter << ' ' << "x2: " << x2 << endl;
            }else   
                x1 ^= *iter;
                // cout << "*iter: " << *iter << ' ' << "x1: " << x1 << endl;
        }
        vector<int> res;
        res.push_back(x1);
        res.push_back(x2);
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,2,3,4,4,5,3};
    Solution sol;
    vector<int> res = sol.singleNumIII(nums);
    cout << res[0] << ' '<< res[1] << endl;
    return 0;
}