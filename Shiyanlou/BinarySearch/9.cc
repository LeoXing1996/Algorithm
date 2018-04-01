#include<iostream>
#include<vector>

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

// class Solution2{
// public:
//     double findMedianSortedArrays(vector<int>&A, vector<int>&B){

//     }
// };

int main(){
    vector<int>A = {1,2,3,4,5,6};
    vector<int>B = {2,3,4,5};
    // Solution sol;
    // cout  << sol.findMedianSortedArrays(A, B);
    int a = 0;
    cout << a/2;
    return 0;
}