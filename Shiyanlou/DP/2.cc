#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        int dp[m+1][n];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=m; ++i){
            for(int j=0; j<n; ++j){
                if(i < A[j]) {
                    if(j==0) dp[i][j] = 0;
                    else dp[i][j] = dp[i][j-1];
                } else {
                    if(j==0) dp[i][j] = A[j];
                    else dp[i][j] = max(dp[i-A[j]][j-1]+A[j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n-1];
    }
};

int main(){
    Solution sol;
    vector<int> A = {3,4,8,5};
    int m = 10;
    cout << sol.backPack(m, A);
}