#include<iostream>

using namespace std;

class Solution{
public:
    countOne(int n){
        int count = 0;
        while(n!=0){
            ++count;
            n &= (n-1); 
        }
        return count;
    }
};

int main(){
    Solution sol;
    // cout << sol.countOne(32) <<endl;
    // cout << sol.countOne(5) <<endl;
    cout << sol.countOne(1023) <<endl;
    return 0;
}