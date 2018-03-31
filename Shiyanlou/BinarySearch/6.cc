#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &A, int target) {
        if(A.size()==0)
            return -1;
        int hb = A.size()-1;
        int lb = 0;
        int mid;
        
        if(target==A[0])
            return 0;
        else if(target == *(A.end()-1))
            return A.size()-1;
        else if(target>A[0]){
            while(lb+1<hb){
                mid = lb + (hb - lb)/2;
                if(A[mid]==target) return mid;
                if(A[mid]>target) hb = mid;
                else if(A[mid]<target && A[mid]<A[lb]) hb = mid;
                else if(A[mid]<target && A[mid]>A[lb]) lb = mid;
            }
        }else{
            while(lb+1<hb){
                mid = lb+(hb-lb)/2;
                if(A[mid]==target) return mid;
                if(A[mid]>A[0]) lb = mid;
                else if(A[mid] < target) lb = mid;
                else if(A[mid] > target) hb = mid;
            }
        }
        return -1;   
    }
};

int main(){
    int a[7] = {4,5,6,7,1,2,3};
    vector<int> A(a, a+7);
    Solution sol;
    cout << sol.search(A, 7) << endl;

    return 0;
}