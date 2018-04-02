#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        vector<int>C;
        vector<int>::iterator iA = A.begin();
        vector<int>::iterator iB = B.begin();
        int SIZE = A.size()+B.size();
        int mid = SIZE/2;
        int count = 0;
        
        while(iA!=A.end()&&iB!=B.end() && count<mid+1){
            ++count;
            if(*iA<*iB) {C.push_back(*iA);++iA;}
            else {C.push_back(*iB);++iB;}
        }
        
        while(iA!=A.end() && count < mid+1){
            C.push_back(*iA);
            ++count;
            ++iA;
        }
        while(iB!=B.end() && count < mid+1){
            C.push_back(*iB);
            ++count;
            ++iB;
        }
        
        if(SIZE%2==0){
            return (double(C[mid]) + double(C[mid-1]))/2;
        }else{
            return C[mid];
        }
    }
};

class Solution2{
private:
    int findkth(vector<int>&A, int A_start, vector<int>&B, int B_start, int k){
        //A B 中某一个被完全去除
        if(A_start>=A.size())
            return B[B_start+k-1];
        if(B_start>=B.size())
            return A[A_start+k-1];
        //递归终止
        if(k==1)
            return A[A_start]>B[B_start] ? B[B_start] : A[A_start];
        
        int A_key = A_start + k/2 - 1 <= A.size() - 1? 
                    A[A_start + k/2 - 1] : INT_MAX;
        int B_key = B_start + k/2 - 1 <= B.size() - 1? 
                    B[B_start + k/2 - 1] : INT_MAX;
        if(A_key>B_key)
            return findkth(A, A_start, B, B_start + k/2, k-k/2);
        else    
            return findkth(A, A_start + k/2, B, B_start, k-k/2);
    }
public:
    double findMedianSortedArrays(vector<int>&A, vector<int>&B){
        int SIZE = A.size() +  B.size();
        int K = SIZE / 2;
        if(SIZE % 2 == 1)
            return findkth(A, 0, B, 0, K+1);
        else{
            return (double(findkth(A, 0, B, 0, K)) + double(findkth(A, 0, B, 0, K+1)))/2;
        }    
    }
};

int main(){
    vector<int>A = {1,2,3,4,5,6};
    vector<int>B = {2,3,4,5};
    Solution2 sol;
    cout  << sol.findMedianSortedArrays(A, B);
    return 0;
}