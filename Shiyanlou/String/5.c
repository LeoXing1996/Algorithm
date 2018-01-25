#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define len 4

void solution(char**);
void sort(char*);

int main(){
    char** given = (char**)malloc(sizeof(char*)*len);
    given[0] = "lint";
    given[1] = "intl";
    given[2] = "inlt";
    given[3] = "int";

    solution(given);
    return 0;
}

void solution(char** given){
    char** sorted = (char**)malloc(sizeof(char*)*len);
    for(int i=0; i<len; ++i){
        sorted[i] = (char*)malloc(sizeof(char)*(strlen(given[i])));
        strcpy(sorted[i], given[i]);
        sort(sorted[i]);
    }

    int visited[len];
    int res[len];
    int count = 0;
    bool flag=false;
    for(int i=0; i<len; ++i){
        visited[i] = 0;
        res[i] = -1;
    }

    for(int i=0; i<len; ++i){
        flag = false;
        if(visited[i]!=0)
            continue;
        visited[i]=1;
        for(int j=i+1; j<len; ++j){
            if(!strcmp(sorted[i], sorted[j])){
                res[count++] = j;
                visited[j]=1;
                flag = true;
            }
        }
        if(flag==true) res[count++]=i;
    }
    for(int i=0; i<len; ++i){
        if(res[i]!=-1){
            printf("%s ",given[i]);
        }
    }
}

void sort(char* t){
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