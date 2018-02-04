#include<stdio.h>
#include<stdlib.h>
int a[8]={0,4,4,0,0,2,4,4};
int value = 4;

int removeElement(int* nums, int numsSize, int val);

int main(){
    removeElement(a, 8, value);

    return 0;
}

int removeElement(int* nums, int numsSize, int val) {
    int e = numsSize;
    for(int i=0; i<e; ++i){
        if(nums[i]==val){
            nums[i] = nums[e-1];
            --e;
            --i;
        }
    }
    return e;
}