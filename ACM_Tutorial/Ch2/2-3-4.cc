#include<iostream>
using namespace std;
#define n 3
#define W 7
int w[n] = {3,4,2};
int v[n] = {4,5,3};
int dp[n+1][W+1];

void solution();
int main(){
    solution();
    return 0;
}

void solution(){
    for(int i=0; i<W; ++i)
        dp[0][i] = 0;
    for(int i=0; i<n; ++i)
        dp[i][0] = 0;

    for(int i=0; i<n; ++i){
        for(int j=0 ; j<=W; ++j){
            if(j<w[i])
                dp[i+1][j] = dp[i][j];
            else{
                dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[n][W];
    
}