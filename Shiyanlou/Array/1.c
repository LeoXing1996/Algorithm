#include<stdio.h>
#include<stdlib.h>
int a[8]={0,4,4,0,0,2,4,4};
int value = 4;

int * solution();

int main(){
    solution();
    return 0;
}

int* solution(){
    int count = 0;
    for(int i=0; i<8; ++i){
        if(a[i]!=value) count++;
    }
    int * res = (int*)malloc(sizeof(int)*count);
    int * temp = res;
    for(int i=0; i<8; ++i){
        if(a[i]!=value){
            *temp = a[i];
            ++temp;
        }
    }
    return res;
}