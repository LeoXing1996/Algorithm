#include<iostream>

using namespace std;

class Solution{
public:
    int fibonacci(int n) {
        if(n==0)
            return -1;
        int fib[2]= {0,1};
        if(n==1||n==2)
            return fib[n-1];
        int temp;
        for(int i=3; i<=n; ++i){
            temp = fib[0] + fib[1];
            // cout << fib[0] << ' ' << fib[1] << ' ' << temp<<endl;
            fib[0] = fib[1];
            fib[1] = temp;
        }
        return fib[1];
    }
};

int main(){
    Solution sol;
    cout << sol.fibonacci(10);
    return 0;
}