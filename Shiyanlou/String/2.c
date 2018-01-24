#include<stdio.h>
#include<string.h>
char* Solution(char*, int);
int main(){
    char ch[]= "abcdef";
    int offset = 3;
    char* newch = Solution(ch, offset);
    printf("%s", newch);
    return 0;
}

char* Solution(char* string, int offset){
    int len = strlen(string);
    char temp;
    for(int i=0; i<offset; ++i){
        temp = string[len-1];   //最后一个字符
        for(int j=0; j<len-1;++j){
            string[len-1-j] = string[len-2-j];
        }
        string[0] = temp;
    }
    return string;
}