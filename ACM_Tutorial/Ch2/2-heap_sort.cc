#include<iostream>

using namespace std;

//堆排序——建立大顶堆，实现优先队列
void heap_sort(int (&array)[5], int m);
int main(){
    int array[5] = {2,7,5,4,8};
    int m = 5;
    heap_sort(array, m);
    
    return 0;
}

void heap_sort(int (&array)[5], int m){
    for(int i=0; i<m; ++i){ //第i次排序
        int len = m-i;  //数组长度
        for(int j=(len/2-1); j>=0; --j){
            int temp = 2*j+1;
            for(int k=j; temp<=len-1; k=temp, temp=2*temp+1){
                if(array[temp]<array[temp+1] && temp+1<=len-1) ++temp;
                if(array[k]>=array[temp]) break;
                else
                    swap(array[temp], array[k]);
            }
        }
        printf("%d ",array[0]);
        swap(array[0], array[len-1]);
    }
}