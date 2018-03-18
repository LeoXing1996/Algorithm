#include<iostream>
#include "dj_set.h"

using namespace std;

void solution();
int K = 7;
int N = 100;
int T[7] = {1,2,2,2,1,2,1};
int X[7] = {101,1,2,3,1,3,5};
int Y[7] = {1,2,3,3,3,1,5};
int main(){
    djset a(10);
    a.unit(2,3);
    a.unit(3,4);
    a.unit(1,2);
    cout << a.find(1) << a.find(2) << a.find(3)<< a.find(4) << a.find(5) << endl;
    solution();
    return 0;
}

void solution(){
    djset s(N*3);
    int err = 0;
    for(int i=0; i<K; ++i){
        if(X[i]>N || Y[N]>N) {
            ++err;
            continue;
        }
        if(T[i]==1){
            if(s.find(X[i]-1)==s.find(Y[i]-1+N) || s.find(X[i]-1)==s.find(Y[i]-1+2*N)){
                ++err;
                continue;
            }
            s.unit(X[i]-1, Y[i]-1);
            s.unit(X[i]-1+N, Y[i]-1+N);
            s.unit(X[i]-1+2*N, Y[i]-1+2*N);
        }else{
            if(s.find(X[i]-1)==s.find(Y[i]-1) || s.find(X[i]-1+N)==s.find(Y[i]-1)){
                ++err;
                continue;
            }else{
                s.unit(X[i]-1, Y[i]-1+N);
                s.unit(X[i]-1+N, Y[i]-1+2*N);
                s.unit(X[i]-1+2*N, Y[i]-1);
            }
        }
    }
    cout << err;
}