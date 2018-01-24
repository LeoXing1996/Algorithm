#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int solution_bf(char*, char*);
int solution_kmp(char*, char* );
void next_val(char*, int[]);
int main(){
    char source1[] = "source";
    char target1[] = "target";
    char source2[] = "abcdabcdefg";
    char target2[] = "efg";
    printf("%d\n", solution_bf(source1, target1));
    printf("%d\n", solution_bf(source2, target2));
    printf("%d\n", solution_kmp(source1, target1));
    printf("%d\n", solution_kmp(source2, target2));
    return 0;
}

int solution_bf(char* s, char* t){
    int lens = strlen(s);
    int lent = strlen(t);
    //i为起始比较位置
    for(int i=0; i<=lens-lent; ++i){
        //j为当前进行比较的模式串位点
        int j=0;
        for( ; j<lent; ++j){
            if(s[i+j]!=t[j]) break;
        }
        if(j==lent) return i;
    }
    return -1;
}

int solution_kmp(char* s, char* t){
    int lens = strlen(s);
    int lent = strlen(t);
    int next[lent]; 
    int i = 0;
    int j = 0;
    next_val(t, next);
    while(i<lens&&j<lent){
        if(s[i]==t[j]||j==-1){
            ++i; ++j;
        }else{
            j = next[j];
        }
    }
    if(j==lent) return i-j;
    else return -1;    
}

void next_val(char* t, int next[]){
    int lent = strlen(t);
    next[0] = -1;
    int i=0;
    int j=-1;
    while(i<lent-1){
        if(j==-1||t[j]==t[i]){
            ++i; ++j; next[i]=j;
        }
        else
            j = next[j];
    }
}