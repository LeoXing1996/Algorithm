#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int n = A.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        int p = 0;
        while(p<n && dp[p]==1){
            for(int i=0; i<A[p]; ++i){
                if(p+1+i == n-1) return true;
                dp[p+1+i] = 1;
            }
            ++p;
        }
        return dp[n-1];
    }

};

int main(){}