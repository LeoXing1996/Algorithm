#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int solution(char*, char*);

int main(){
    char* s1 = "asdf";
    char* t1 = "fdsa";
    char* s2 = "qaz";
    char* t2 = "qwe";
    printf("char1: %d\n",solution(s1,t1));
    printf("char2: %d\n",solution(s2,t2));
    return 0;
}

int solution(char*s, char*t){
    int lens = strlen(s);
    int lent = strlen(t);
    
    if(lens!=lent)
        return -1;
    int i=0;
    for(; i<lens; ++i){
        if(s[i]!=t[lent-i-1]) {
            break;
        }
    }
    if(i!=lens)
        return -1;
    else
        return 1;
}