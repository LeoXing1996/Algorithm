#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n==0) return 0;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.climbStairs(3);
}
