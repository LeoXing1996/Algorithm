#include<stdio.h>

int N=6;
int R=10;
int x[] = {1,7,15,20,30,50};
void solution();

int main(){
    solution();
    return 0;
}

void solution(){
    int count = 0;
    int sum =0;
    while(count<N){
        int i=count+1;
        while(x[i]-x[count]<R && i<N) ++i;
        if(count == i-1){
            ++count;
        } else {
            int j=i+1;
            while(x[j]-x[i]<R && j<N) ++j;
            // if(i == j-1) count = i+1;
            // else count = j;
            count = j;
        }
        ++sum;
    }
    printf("%d", sum);
}