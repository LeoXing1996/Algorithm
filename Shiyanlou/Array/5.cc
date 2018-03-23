#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution{
private:
    int A[8] = {4,5,6,7,0,1,2,3};
    int len = 8;
public:
    int* subarrayRotate(){
        int* res = new int[len];
        int mid = 1;
        // 找出中心
        while(A[mid]>A[mid-1])
            ++mid;
        // 反转前部
        int Right_mid = ceil((double(len)-1 + double(mid))/2);
        int Left_mid = ceil((double(mid)-1)/2);
        for(int i=mid-1; i>=Left_mid; --i){
            int temp = A[i];
            A[i] = A[mid-1-i];
            A[mid-1-i] = temp;
        }
        // 反转后部
        for(int i=len-1; i>=Right_mid; --i){
            int temp = A[i];
            A[i] = A[len+mid-i-1];
            A[len+mid-i-1] = temp;
        }
        for(int i=len-1; i>=0; --i){
            cout << A[i] << ' ' ;
            res[len-1-i] = A[i];
        }
        return res;
    }
    vector<int> subarrayRotate_vec(){
        vector<int> res;
        int mid = 1;
        // 找出中心
        while(A[mid]>A[mid-1])
            ++mid;
        // 反转前部
        int Right_mid = ceil((double(len)-1 + double(mid))/2);
        int Left_mid = ceil((double(mid)-1)/2);
        for(int i=mid-1; i>=Left_mid; --i){
            int temp = A[i];
            A[i] = A[mid-1-i];
            A[mid-1-i] = temp;
        }
        // 反转后部
        for(int i=len-1; i>=Right_mid; --i){
            int temp = A[i];
            A[i] = A[len+mid-i-1];
            A[len+mid-i-1] = temp;
        }

        for(int i=len-1; i>=0; --i){
            cout<< A[i] << ' ' ;
            res.push_back(A[i]);
        }
        cout << endl;
        return res;
    }
};

int main(){
    Solution sol;
    // int * res = sol.subarrayRotate();
    // for(int i=0; i<8; ++i){
    //     cout << res[i] << ' ';
    // }
    // cout << endl;
    vector<int> res2 =sol.subarrayRotate_vec();
    for(vector<int>::iterator iter = res2.begin(); iter != res2.end(); ++iter){
        cout << *iter << ' ';
    }
    return 0;
}