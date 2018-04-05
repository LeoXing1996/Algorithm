#include<iostream>
// #include<vector>
using namespace std;
class Solution{
public:
    int convertA2B(int A, int B){
        int count = 0;
        // A=-1 B=1 AxorB=-2
        int AxorB = A^B;
        // 这里会陷入死循环
        while (AxorB!=0){
            ++count;
            AxorB = AxorB & AxorB-1;
        }
        return count;
    }
};

int main(){
    Solution sol;
    cout << sol.convertA2B(-1, 1) <<endl;
    return 0;
}