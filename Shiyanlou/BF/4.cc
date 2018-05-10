#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty()) return res;

        sort(nums.begin(), nums.end());
        res.push_back(nums);
        
        while(nextPer_cc(nums)){
            res.push_back(nums);
        }
        
        return res;
    }
private:
    bool nextPer(vector<int> & curr){
        // step 1: find the suffix
        int toChange_L = curr.size()-1;
        
        while(toChange_L > 0 && curr[toChange_L-1] >= curr[toChange_L]) 
            --toChange_L;
        if(toChange_L == 0) return false;
        --toChange_L;

        // step 2: find where to swap
        int toChange_R = curr.size()-1;
        while(curr[toChange_R] <= curr[toChange_L]) --toChange_R;

        // step 3: swap
        int temp = curr[toChange_L];
        curr[toChange_L] = curr[toChange_R];
        curr[toChange_R] = temp;

        // step 4: reverse
        int i = toChange_L+1, j = curr.size()-1;
        while(i<j){
            temp = curr[i];
            curr[i] = curr[j];
            curr[j] = temp;
            ++i;
            --j;
        }
        return true;
    }

    bool nextPer_cc(vector<int> & curr){
        
        vector<int>::iterator toChange_L = curr.end()-1;
        while(toChange_L != curr.begin() && *(toChange_L-1) >= *toChange_L) --toChange_L;

        if(toChange_L == curr.begin()) return false;
        --toChange_L;

        vector<int>::iterator toChange_R = curr.end()-1;
        while(*toChange_R <= *toChange_L) --toChange_R;

        iter_swap(toChange_L, toChange_R);
        
        reverse(toChange_L+1, curr.end());
        return true;
    }
};

int main(){
    vector<int> a = {1,2};
    Solution sol;
    vector<vector<int> > res = sol.permuteUnique(a);
    cout << res.size();
    return 0;
}