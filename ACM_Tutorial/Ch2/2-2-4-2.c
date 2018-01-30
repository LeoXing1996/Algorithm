#include<stdio.h>

int N=5;
int L[] = {1,2,3,4,5};

void solution();

int main(){
    solution();
    return 0;
}

void solution(){
    int sum = 0;
    int count = 0;
    while(count < N-1){
        int i=0;
        int j=1;
        if(L[i]>L[j]){
            int temp = j;
            j=i;
            i=temp;
        }
        for(int k=2; k<N-count; ++k){
            if(L[i]>L[k]) {
                j=i;
                i=k;
            } else if(L[j]>L[k]){
                j=k;
            }
        }
        sum += L[i];
        sum += L[j];
        L[i] = L[i]+L[j];
        L[j] = L[N-count-1];
        ++count;
    }
    printf("%d", sum);
}