#include<stdio.h>
#define m 10
#define n 13
char field[m][n] = {"W........WW.",\
                    ".WWW.....WWW",\
                    "....WW...WW.",\
                    ".........WW.",\
                    ".........W..",\
                    "..W......W..",\
                    ".W.W.....WW.",\
                    "W.W.W.....W.",\
                    ".W.W......W.",\
                    "..W.......W."};

void dfs(int,int);
int main(){
    int count = 0;
    for(int i=0;i<m;++i){
        for(int j=0;j<n-1;++j){
            if(field[i][j]=='W'){
                dfs(i,j);
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}

void dfs(int a, int b){
    field[a][b] = '.';
    for(int i=a-1;i<=a+1;++i){
        if(i<0||i>m) continue;
        for(int j=b-1;j<=b+1;++j){
            if(i==a&&j==b || j<0 || j>=n) continue;
            if(field[i][j]=='W'){
                dfs(i,j);
            }
        }
    }
}