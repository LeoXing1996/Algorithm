#include<iostream>

using namespace std;

class Solution{
public:
    int updataBits(int n, int m, int i, int j){
        m <<= i;
        int mask;
        if(j<31){
            mask = -1;
            mask -= ((1 << j+1) - 1);
        } else{
            mask = 0;
        }
        mask |= ((1 << i) - 1);
        n &= mask;
        return n | m;
    }

};

int main(){
    Solution sol;
    cout <<sol.updataBits()
    return 0;
}