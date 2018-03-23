#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int A[5] = {1,2,3,4,5};
    int len = 5;
public:
    int* arrayExclude(){
        int* B = new int[len];
        fill(B, B+len, 1);
        for(int i=0; i<len; ++i){
            for(int j=0; j<len; ++j){
                if(i!=j) B[j] = B[j]*A[i];
            }
        }
        return B;
    }
    int* arrayExclude_par(){
        int * B = new int[len];
        int LtoR[len];
        int RtoL[len];
        fill(LtoR, LtoR+len, 1);
        fill(RtoL, RtoL+len, 1);
        LtoR[0] = A[0];
        RtoL[len-1] = A[len-1];
        for(int i=1; i<len; ++i){
            LtoR[i] = LtoR[i-1] * A[i];
            RtoL[len-i-1] = RtoL[len-i] * A[len-i-1];
        }
        B[0] = RtoL[1];
        B[len-1] = LtoR[len-2];
        for(int i=1; i<len-1; ++i){
            B[i] = LtoR[i-1] * RtoL[i+1];
        }
        return B;
    }
};

int main(){
    Solution sol1;
    int * res1 = sol1.arrayExclude();
    int * res2 = sol1.arrayExclude_par();
    for(int i=0; i<5; ++i){
        cout << res1[i] <<' ';
    }
    cout << endl;
    for(int i=0; i<5; ++i){
        cout << res2[i] <<' ';
    }
    return 0;
}