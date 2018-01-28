#include<stdio.h>
#include<string.h>

void isMatch(char[], char[]);

int main(){
    isMatch("aa","a");
    isMatch("aa","aa");
    isMatch("aaa","aa");
    isMatch("aa", "*");
    isMatch("aa", "a*");
    isMatch("ab", "?*");
    isMatch("aab", "c*a*b");
    return 0;
}

void isMatch(char s[], char t[]){
    int lens = strlen(s);
    int lent = strlen(t);
    int is = 0;
    int it = 0;
    int t_start = 0;
    int s_start = 0;
    int flag = 1;
    while(is < lens){
        if(t[it]=='?' || s[is]==t[it]){++is; ++it;}
        else if(t[it]=='*'){
            t_start = it+1; ++it;
            s_start = is;}
        else if(t_start!=0){
            is = ++s_start;
            it = t_start;

        }
        else{
            flag=0;
            break;
        }
    }
    while(t[it]=='*') ++it;
    if(it != lent || !flag){
        printf("False.\n");
    }else{
        printf("True.\n");
    }
}