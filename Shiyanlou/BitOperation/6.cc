#include<iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        
        while(n!=0){
            n = n/5;
            count += n;
        }
        return count;
    }
};

int main(){
    Solution sol;
    cout << sol.trailingZeroes(55) << endl;
    return 0;
}