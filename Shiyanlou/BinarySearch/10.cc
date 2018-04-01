#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        int lb = 0;
        int hb = x;
        long long mid; //very very important!!!!!
        while(lb+1<hb){
            mid = (lb+hb)/2;
            if(mid*mid <= x && (mid+1)*(mid+1)>x)
                return mid;
            if(x/mid>mid)
                lb =mid;
            else
                hb = mid;
        }
    }
};

int main(){
    Solution sol;
    int a = 2147483647;
    cout << sol.sqrt(a);
    

    return 0;
}