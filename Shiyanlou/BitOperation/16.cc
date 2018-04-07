#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution{
public:
    int majorityNumber(vector<int>& nums, int k){
        map<int,int> hash;
        for(auto n:nums){
            if(hash.find(n)==hash.end()) {
                if(hash.size()<k)
                    hash[n] = 1;
                else{
                    for(auto &n : hash){
                        -- n.second;
                    }
                }
            }else ++hash[n];
        }     
        int num=0, count=0;
        for(auto n:hash){
            if(n.second>count){
                count = n.second;
                num = n.first;
            }
        }
        return num;
    }
};

int main(){
    vector<int> nums= {3,1,2,3,2,3,3,4,4,4};
    int k=3;
    Solution sol;
    cout << sol.majorityNumber(nums, k);
    return 0;
}