#include<iostream>
using namespace std;

#define n 4
#define m 3

int solution(int,int);
void solution2();
int main(){
    int res = solution(3,4);
    printf("%d\n", res);
    solution2();
    return 0;
}

int solution(int i, int j){
    if(i>j || i==1)
        return 1;
    else{
        return solution(i, j-i) + solution(i-1, j);
    }
}

void solution2(){
    int dp[m+1][n+1];
    //fill(dp[1],dp[1]+n+1,1);
    fill_n(dp[1]+1,n,1);
    for(int i=2; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(i > j) dp[i][j] = 1;
            else if(i==j) dp[i][j] = 1+dp[i-1][j];
            else dp[i][j] = dp[i][j-i] + dp[i-1][j];
        }
    }
    printf("%d\n", dp[m][n]);
}