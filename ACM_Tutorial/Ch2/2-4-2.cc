#include<iostream>
#include<queue>

using namespace std;

void solution(int N, int L[3]);
int main(){
    int N=3;
    int L[3] = {8,5,8};
    solution(N, L);
    return 0;
}

void solution(int N, int L[3]){
    priority_queue <int, vector<int>, greater<int>> que;
    int res =0 ;
    for(int i=0; i<N; ++i){
        que.push(L[i]);
    }
    while(!que.empty()){
        int ans = que.top();
        que.pop();
        if(!que.empty()){
            ans += que.top();
            que.pop();
            res += ans;
            que.push(ans);
        }
    }
    printf("%d", res);
}