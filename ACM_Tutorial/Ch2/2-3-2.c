#include<stdio.h>

int n = 3;
int W = 7;
int w[3] = {3,4,2};
int v[3] = {4,5,3};

void solution();

int main(){
    solution();
    return 0;
}

void solution(){
    int dp[n+1][W+1];
    //init
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=W; ++j){
            dp[i][j] = 0;
        }
    }
    for(int i=0; i<n;++i){
        for(int j=0; j<=W; ++j){
            if(j<w[i])
                dp[i+1][j] = dp[i][j];
            else{
                if(dp[i][j]>dp[i+1][j-w[i]]+v[i]){
                    dp[i+1][j] = dp[i][j];
                }else{
                    dp[i+1][j] = dp[i+1][j-w[i]]+v[i];
                }
            }
        }
    }
    printf("%d", dp[n][W]);
}