#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void partitionArray(vector<int>& nums){
        int len = nums.size();
        int front = 0;
        int end = len-1;
        while(front < end){
            while(front < end && nums[front]%2==1) ++ front;
            while(front < end && nums[end]%2==0) -- end;
            int temp = nums[front];
            nums[front] = nums[end];
            nums[end] = temp;
        }
    }
};

int main(){
    int a[5] = {1,2,3,4,5};
    vector<int> nums(a, a+5);
    Solution sol;
    sol.partitionArray(nums);
    for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}