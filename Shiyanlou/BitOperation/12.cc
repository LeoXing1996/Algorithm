#include<iostream>
#include<ctime>
using namespace std;

class Solution{
public:
    int AplusB(int a, int b){
        int _b; // 进位
        int _a; // 加和
        while(b!=0){
            _a = a ^ b;
            _b = (a & b) << 1;
            a = _a;
            b = _b;
        }
        return a;
    }
};

int main(){
    Solution sol;
    clock_t start = clock();
    cout << sol.AplusB(5,6) << endl;
    clock_t end = clock();
    cout << "Cost" <<(double)( end - start )/CLOCKS_PER_SEC << 's' <<endl;
    return 0;
}