#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[] = "the sky is blue";
void solution(char[]);
int main(){
    strlen(s);
    solution(s);
    return 0;
}

void solution(char s[]){
    int num=0;  //单词个数
    int start=0;
    //找前导空格
    while(s[start]==' ')
        ++start;
    for(; s[start]!='\0';++start){
        //防止中间多个空格以及结尾空格
        if(s[start]==' ' && s[start+1]!=' ' && s[start+1]!='\0'){
            ++num;
        }
    }
    ++num;
    int end = strlen(s);
    char **t = (char**)malloc(sizeof(char*)*num);
    char** curr = t;
    for(int count=num; count>0; --count){
        while(s[end]==' ') --end;
        int i=end;
        while(s[i]!=' ' && i>=0) --i;
        *curr = (char*)malloc(sizeof(char)*(end-i+1));
        char* temp = *curr;
        
        for(int j=0; j<end-i; ++j){
            *temp = s[i+j+1];
            ++temp;
        }
        *temp = '\0';
        end = i;
        ++curr;
    }
    for(int i=0; i<num; ++i){
        printf("%s ",*(t+i));
    }
}