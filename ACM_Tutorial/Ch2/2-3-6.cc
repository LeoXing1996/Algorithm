#include<iostream>
#include<limits.h>
using namespace std;
#define n 5
int a[] = {4,2,3,1,5};

void solution();
void solution2();
void solution3();
int main(){
    solution();
    solution2();
    solution3();
    return 0;
}

void solution(){
    int dp[n];
    for(int i=0; i<n; ++i){
        dp[i] = 1;
        for(int j=0; j<i; ++j){
            if(a[i]>a[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    printf("%d\n", dp[n-1]);
}

void solution2(){
    int dp[n];
    fill(dp, dp+n, INT_MAX);
    for(int i=0; i<n; ++i){
        //对a[]中元素进行循环
        dp[0] = min(dp[0], a[i]);
        for(int j=0; j<i; ++j){
             //对dp[]中元素进行循环
             if(a[i]>dp[j])
                dp[j+1] = min(dp[j+1], a[i]);
        }
    }
    int count=0;
    for( ; count<n; ++count){
        if(dp[count] == INT_MAX)
            break;
    }
    printf("%d\n", count);
}

void solution3(){ //使用 STL 中的lower_bound
    int dp[n];
    fill(dp, dp+n, INT_MAX);
    for(int i=0; i<n; ++i){
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
    printf("%d\n", lower_bound(dp, dp+n, INT_MAX) - dp);
}