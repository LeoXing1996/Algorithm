#include<iostream>
#include<vector>
#include<limits.h>
#include<cstring>
using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        int dp[size][size] ;
        // memset(dp, INT_MAX, sizeof(dp));
        for(int i =0; i<size; ++i){
            for(int j=0; j<size; ++j){
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][0] = triangle[0][0];
        int res = INT_MAX;
        for(int i=1; i<size; ++i){
            for(int j=0; j<=i; ++j){
                if(j==0){
                    dp[i][0] = dp[i-1][0] + triangle[i][j];
                } else if(j < i){
                    int r = dp[i-1][j-1] < dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j] ;
                    dp[i][j] = r + triangle[i][j];
                } else {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
            }
        }
        for(int j=0; j<size; ++j){
            res = res < dp[size-1][j] ? res : dp[size-1][j];
        }
        return res;
    }
};

int main(){
    vector<vector <int> > triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Solution sol;
    int res = sol.minimumTotal(triangle);
    cout << res;
}
