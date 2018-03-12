#include<iostream>
#include <algorithm>

using namespace std;

int transfer(int, int);
int dp[4][5];
int main(){
    fill(dp[0], dp[0]+20, 0);

    int res = transfer(0,0);
    cout << '\n';
    for(int i=0; i<4; ++i){
        for(int j=0; j<5; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int transfer(int m, int n){
    if(m==2 || n==2){    //判断是否成功
        dp[m][n] = 1;
        return 1;
    }
    if(dp[m][n]==1)     //判断是否访问过
        return 0;
    dp[m][n] = 1;       //标记访问
    if(transfer(3,n)){   //3加满
        cout << '(' << 3 << ',' << n <<')';
        return 1;
    }
    if(transfer(m,4)){   //4加满
        cout << '(' << m << ',' << 4 <<')';
        return 1;}
    if(transfer(0,n)){   //3倒空
        cout << '(' << 0 << ',' << n <<')';
        return 1;}
    if(transfer(m,0)){   //4倒空
        cout << '(' << m << ',' << 0 <<')';
        return 1;}
    // 3->4
    if(m+n>4){
        if(transfer(m+n-4,4)){
            cout << '(' << m+n-4  << ','<< 4 <<')';
            return 1;
        }
    } else {
        if(transfer(0, m+n)){
            cout << '(' << 0  << ','<< m+n <<')';
            return 1;
        }
    }
    //4->3
    if(m+n>3){
        if(transfer(3, m+n-3)){
            cout << '(' << 3  << ','<< m+n-3 <<')';
            return 1;
        }
    } else {
        if(transfer(m+n, 0)){
            cout << '(' << m+n << ',' << 0 <<')';
            return 1;
        }
    }
    
    return 0;
}
