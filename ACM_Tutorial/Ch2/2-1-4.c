#include<stdio.h>
#include<stdbool.h>
#define max_n 255

int n = 4;
int k =15;
int a[max_n] = {1,2,4,7};
bool res = false;
void dfs(int,int);

int main(){ 
    dfs(0,0);
    if(res)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

void dfs(int index, int sum){
    if(res==true || index >= n)
        return;
    else{
        if(sum+a[index]==k){
            res = true; return;
        }else{
            dfs(index+1,sum);   //不加a[index]
            dfs(index+1,sum+a[index]);  //加a[index]
        }
    }
}