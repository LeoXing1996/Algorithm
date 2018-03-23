#include<iostream>

using namespace std;

class Solution{
private:
    int nums[5] = {2,2,4,5,1};
    int len = 5;
    int K = 2;
public:
    int arrayPartition(){
        int res;
        int left = 0;
        int right = len-1;
        while(left<right){
            while(left<right && nums[left]<K) ++left;
            while(left<right && nums[right]>=K) --right;
            if(left < right){
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        return left;
    }
    void show(){
        for(int i=0; i<len; ++i){
            cout << nums[i] <<' ';
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    int res = sol.arrayPartition();
    cout << res << endl;
    sol.show();
    return 0;
}