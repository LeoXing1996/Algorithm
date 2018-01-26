#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char string[]="abcdzdcab";
void solution(char[]);

int main(){
    solution(string);
    return 0;
}

void solution(char string[]){
    int lens = strlen(string);
    int res[lens];
    for(int i=1; i<lens-1; ++i){
        res[i]=0;
        for(int j=1; i-j>=0 && i+j <lens; ++j){
            if(string[i+j]==string[i-j]) ++res[i];
            else break;
        }
    }
    int max = res[1];
    int max_ind = 1;
    for(int i=2; i<lens-1; ++i){
        if(max < res[i]) {max = res[i]; max_ind = i;}
    }
    char sub[max*2+2];
    for(int i=0; i<max*2+1; ++i){
        sub[i] = string[max_ind-max+i];
    }
    sub[max*2+1] = '\0';
    printf("%s", sub);

}