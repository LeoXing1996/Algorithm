#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        // if(grid.empty()) return -1;

        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = grid[0][0];
        for(int j=1; j<n; ++j)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i=1; i<n; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){

}