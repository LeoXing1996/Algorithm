#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        int dp[size+1][size+1];

        // for(int i=0; i<size+1; ++i)
        //     fill_n(dp[i], size+1, INT_MAX);

        for(int i=0; i<=size; ++i)
            for(int j=0; j<=size; ++j)
                dp[i][j] = INT_MAX;

        dp[1][1] = triangle[0][0];
        int r1, r2, r3;
        for(int i=2; i<=size; ++i){
            for(int j=1; j<=i; ++j){
                r1 = j==1 ? INT_MAX : dp[i-1][j-1] ;
                r2 = dp[i-1][j];
                r3 = dp[i-1][j+1];
                dp[i][j] = r1 < r2 ? r1 : r2;
                dp[i][j] = dp[i][j] < r3 ? dp[i][j] : r3;
                dp[i][j] += triangle[i-1][j-1];
            }
        }
        int res = INT_MAX;
        for(int j=1; j<=size; ++j){
            cout << dp[size][j]<< endl;
            res = res < dp[size][j] ? res : dp[size][j];
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
