#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int solution(char[], char[]);
void sort(char[]);
int main(){
    char s[] = "abcd";
    char t[] = "bcda";
    sort(t);
    printf("%d\n", solution(s, t));
    return 0;
}

int solution(char s[], char t[]){
    int lent = strlen(t);
    int lens = strlen(s);
    if(lent!=lens)
        return -1;
    for(int i=0; i<lent; ++i){
        if(s[i]!=t[i])
            return -1;
    }
    return 0;
}

void sort(char t[]){
    int lent = strlen(t);
    for(int i=1; i<lent; ++i){
        if(t[i]<t[i-1]){
            char temp = t[i];
            t[i] = t[i-1];
            int j = i-2;
            while(temp<t[j]){
                t[j+1] = t[j];
                --j;
            }
            t[j+1] = temp;
        }
    }
}