#include<iostream>
#include<cstring>
#define n 3
#define K 17

using namespace std;
int a[3] = {3,5,8};
int m[3] = {3,2,2};

void solution();
void solution2();
int main(){
    //solution();
    solution2();
    return 0;
}

void solution(){
    int dp[n+1][K+1];
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=n; ++i)
        dp[i][0] = 1;
    for(int i=0; i<n; ++i){
        for(int j=1; j<=K; ++j){
            // if(a[i]>j)
            //     dp[i+1][j] = dp[i][j];
            // else
            //     dp[i+1][j] = (dp[i][j] || dp[i+1][j-a[i]]);
            for(int k=0; k<m[i] && j>=k*a[i]; ++k){
                dp[i+1][j] = (dp[i+1][j] || dp[i][j-k*a[i]]);
            }
        }
    }
    printf("%d", dp[n][K]);
}

void solution2(){
    int dp[K+1];
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<=K; ++j){
            if(dp[j]>=0)
                dp[j] = m[i];
            else if(j<a[i] || dp[j-a[i]] <=0)
                dp[j] = -1;
            else
                dp[j] = dp[j-a[i]]-1;
        }
    }
    printf("%d", dp[K]);
}