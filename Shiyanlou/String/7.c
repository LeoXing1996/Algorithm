#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char s1[] = "A man, a plan, a canal: Panama";
char s2[] = "race a car";

int solution(char[]);

int main(){
    int res1 = solution(s1);
    int res2 = solution(s2);
    printf("%d\n", res1);
    printf("%d\n", res2);
    return 0;
}

int solution(char s[]){
    int lens = strlen(s);
    int st=0;
    int ed=lens-1;
    while(st!=ed){
        while(!isalpha(s[st]) && st!=ed) ++st;
        while(!isalpha(s[ed]) && st!=ed) --ed;
        if(toupper(s[st])==toupper(s[ed]) && st!=ed) {++st; --ed;}
        else break;
    }
    if(st==ed) return 1;
    else return 0;
}