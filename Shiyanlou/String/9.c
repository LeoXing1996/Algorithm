#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[50] = "Mr John Smith";
int lens = 13;

void solution1();
void solution2();
int main(){
    //solution1();
    solution2();
    return 0;
}

void solution1(){
    int count=0;
    int i=0;
    for(; count<lens; ++count){
        if(s[i]==' '){
            for(int j=lens-count+i+1; j>i+2; --j){
                s[j] = s[j-2];
            }
            s[i++] = '%';
            s[i++] = '2';
            s[i++] = '0';
        }
        else ++i;
    }
    s[i] = '\0';
    printf("%s", s);
}

void solution2(){
    int space=0;
    for(int i=0; i<lens; ++i){
        if(s[i]==' ') ++space;
    }
    int lenS = space*2+lens;
    char new_s[lenS+1];
    new_s[lenS--] = '\0';

    for(int i=lens-1; i>=0; --i){
        if(s[i]==' '){
            new_s[lenS--] = '0';
            new_s[lenS--] = '2';
            new_s[lenS--] = '%';
        }else{
            new_s[lenS--]=s[i];
        }
    }
    printf("%s ", new_s);
}