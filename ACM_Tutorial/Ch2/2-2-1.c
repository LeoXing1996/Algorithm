#include<stdio.h>

int solution(int);

int main(){
    int A=620;
    printf("%d", solution(A));
    return 0;
}

int solution(int A){
    int count = 0;
    while(A!=0){
        if(A>500){
            count += A/500;
            A = A % 500;
        } else if(A>100){
            count += A/100;
            A = A % 100;
        } else if(A>10){
            count += A/10;
            A = A % 10;
        } else if(A>5){
            count += A/5;
            A = A % 5;
        } else{
            count += A;
            A = A % 1;
        }
    }
    return count;
}