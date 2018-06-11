#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class Solution{
public:
    int packII(int m, vector<int> & A, vector<int> & V){
        int n = A.size();
        int dp[m+1][n] ;
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=m; ++i){
            for(int j=0; j<n; ++j){
                if(i < A[j]){
                    if(j==0) dp[i][0] = 0;
                    else dp[i][j] = dp[i][j-1];
                } else {
                    if(j==0) dp[i][0] = V[0];
                    else dp[i][j] = max(dp[i-A[j]][j-1]+V[j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n-1];
    }
};

int main(){
    vector<int> A = {2,3,5,7};
    vector<int> V = {1,5,2,4};
    int m = 10;
    Solution sol;
    cout << sol.packII(m, A, V);
}