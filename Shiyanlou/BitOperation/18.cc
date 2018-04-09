#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    //Wrong answer
    // int uglyNumber(int k){
    //     if(k<=0) return -1;
    //     vector<int>nums = {3,5,7};
    //     if(k<=3) return nums[k-1];
    //     int start = 0;
    //     int end = 3;
    //     int count = 3;
    //     pair<int,int> span = {1,1};
    //     while(count <= k){
    //         //第一轮
    //         int curr = start;
    //         while(curr < end && count <= k){
    //             nums.push_back(nums[0] * nums[curr]);
    //             ++curr;
    //             ++count;
    //         }
    //         // 第二轮
    //         curr = start + span.first;
    //         while(curr < end && count <= k){
    //             nums.push_back(nums[1] * nums[curr]);
    //             ++curr;
    //             ++count;
    //         }
    //         if(count < k) nums.push_back(nums[2] * nums[end]);
    //         ++count;
    //         // 更新
    //         span.first = span.first + span.second + 1; 
    //         span.second = span.second + 1;
    //         start = end ;
    //         end = start + span.first + span.second + 1;
    //         cout << "start: " << start << " end: " << end << " bound: " << start + span.first << endl;
    //     }
    //     return nums[k-1];
    // }

    int uglyNumber_right(int k){
        int ind3 = 0, ind5 =0, ind7 = 0;
        int seq3, seq5, seq7;
        int seq_next;
        vector<int> nums = {1};
        for(int i=0; i<k; ++i){
            seq3 = nums[ind3] * 3;
            seq5 = nums[ind5] * 5;
            seq7 = nums[ind7] * 7;
            seq_next = seq3 < seq5 ? seq3 : seq5;
            seq_next = seq_next < seq7 ? seq_next : seq7;
            if(seq_next == seq3) ++ind3;
            if(seq_next == seq5) ++ind5;
            if(seq_next == seq7) ++ind7;
            nums.push_back(seq_next);
        }
        return nums[k];
    }
    bool isUgly(int num){
        if(num == 0)
            return false;
        while(num%2==0){
            num = num/2;
        }
        while(num%3==0){
            num = num/3;
        }
        while(num%5==0){
            num = num/5;
        }
        if(num!=1) return false;
        else return true;
    }
};

int main(){
    Solution sol;
    // cout << sol.uglyNumber_right(10);
    cout << sol.isUgly(15);
    return 0;
}