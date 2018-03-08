#include<iostream>
#include<queue>
#define N 4  //加油站数量
#define L 25 //总里程
#define P 10 //起始油量
int A[] = {10,14,20,21};  //加油站位置
int B[] = {10,5,2,4};     //加油站油量
using namespace std;

void solution1();
void solution2();
int main(){
    //solution1();
    solution2();
    return 0;
}

void solution1(){
    int count = 0;
    int dmax = P;
    int last = 0;
    while(dmax < L){
        int add = 0;
        for(int i=last; i<N && A[i]<=dmax; ++i){
            if(B[i]>add){
                add = B[i];
                last = i;
            }
        }
        dmax += add;
        ++count;
    }
    if(dmax >= L)
        printf("%d\n", count);
    else
        printf("-1\n");
}

void solution2(){
    priority_queue <int> que;
    int count = 0;
    int p = P;
    for(int i=0; i<N; ++i){
        if(p>=L)
            break;
        else if(p - A[i] >= 0)    //能经过A[i]
            que.push(B[i]);
        else{
            while(p - A[i] < 0 || !que.empty()){
                p += que.top();
                que.pop();
                ++count;
            }
            if(p - A[i] <0){
                count = -1;
                break;
            }
        }
    }
    printf("%d\n", count);
}