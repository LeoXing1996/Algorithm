#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* solution(int);

int main(){
    printf("%s\n", solution(1));
    printf("%s\n", solution(2));
    printf("%s\n", solution(3));
    printf("%s\n", solution(4));
    printf("%s\n", solution(5));
    return 0;
}

char* solution(int n){
    if(n==1) return "1";
    else{
        char * last = solution(n-1);
        int len = strlen(last);
        char * curr = (char*)malloc(sizeof(char)*2*len);
        char * temp = curr;
        char * start = last;
        while(*start!='\0'){
            char * i = start;
            int count=1;
            for(; *i == *(i+1) && i!='\0'; ++i){
                ++count;
            }
            char c = count + '0';
            *temp++ = c;
            *temp++ = *start;
            start = i+1;
        }
        *temp = '\0';
        return curr;
    }
}