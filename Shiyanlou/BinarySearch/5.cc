#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        // write your code here
        int hb = A.size()-1;
        int lb = 0 ;
        int mid;
        while(lb+1<hb){
            mid = lb + (hb-lb)/2;
            if(A[mid-1]<A[mid] && A[mid]>A[mid+1])  return mid;
            //导数大于0
            if(A[mid-1]<A[mid] && A[mid]<A[mid+1]) lb = mid;
            //导数小于0
            // if(A[mid-1]>A[mid] && A[mid]>A[mid+1])
            else
                hb = mid;
        }
    }
};

int main(){
    int a[8] = {1,2,1,3,4,5,7,6};
    vector<int>A(a, a+8);
    Solution sol;
    int res = sol.findPeak(A);
    cout << res << endl;
    return 0;
}