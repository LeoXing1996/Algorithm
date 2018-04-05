#include<iostream>

using namespace std;

class Solution{
public:
    int binarySearchTree(int n){
        if(n==0)
            return 1;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        fill(dp+2, dp+n+1, 0);
        for(int i=2; i<=n; ++i){
            for(int j=0; j<i; ++j){
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.binarySearchTree(4);
    return 0;
}