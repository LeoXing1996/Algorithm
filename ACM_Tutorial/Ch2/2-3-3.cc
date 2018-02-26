#include<iostream>
#include<string.h>
using namespace std;

#define m 4
#define n 4
char s[] = "abcd";
char t[] = "becd";
int dp[m+1][n+1];
void solution();

int main(){
    cout << "hello" << '\n';
    solution();
}

void solution(){
    for(int i=0; i<m; ++i)
        dp[i][0] = 0;
    for(int j=0; n<m; ++j)
        dp[0][j] = 0;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(s[i]==t[j])
                dp[i+1][j+1] = dp[i][j] +1;
            else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    cout << dp[m][n];
}