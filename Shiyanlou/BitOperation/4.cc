#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool checkPower(int n){
        if(n<1)
            return false;
        int firstOne = n - (n & (n-1));
        if((firstOne & n)==n)
            return true;
        else    
            return false;
    }

    bool checkPower2(int n){
        if(n<1)
            return 0;
        if((n & n-1)==0)
            return true;
        else    
            return false;
    }
};

int main(){
    Solution sol;
    cout << sol.checkPower(5) << ' ' << sol.checkPower(1) << endl;
    return 0;
}