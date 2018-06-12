#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp[m][n];
        int n_=0;
        while(n_<m && obstacleGrid[n_][0]==0){
            dp[n_][0] = 1;
            ++n_;
        }
        n_ = 0;
        while(n_<n && obstacleGrid[0][n_]==0){
            dp[0][n_] = 1;
            ++n_;
        }
        
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){

}