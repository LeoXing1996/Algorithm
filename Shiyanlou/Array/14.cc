#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int>mergeSortedArray(vector<int> &A, vector<int> &B){
        vector<int> res;
        int ca = 0;
        int cb = 0;
        while(ca< A.size() && cb<B.size()){
            if(A[ca]<B[cb]){
                res.push_back(A[ca]);
                ++ca;
            }
            else {
                res.push_back(B[cb]);
                ++cb;
            }
        }
        if(ca<A.size()){
            for(int i=ca; i<A.size(); ++i)
                res.push_back(A[i]);
        }else{
            for(int i=cb; i<B.size(); ++i)
                res.push_back(B[i]);
        }

        return res;
    }
};

int main(){
    int a[4] = {1,2,3,4};
    int b[4] = {2,4,5,6};
    vector<int> A(a, a+4);
    vector<int> B(b, b+4);
    vector<int> res;
    Solution sol;
    res = sol.mergeSortedArray(A, B);

    for(vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter){
        cout << *iter << ' ';
    }
    return 0;
}