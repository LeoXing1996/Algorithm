#include<iostream>
// #include<>

using namespace std;

class Solution{
public:
    int digitCounts(int k, int n) {
        if(k==0 && n==0) return 1;
        int base = 1; //统计位数
        int res =0;
        int lower_base = 0 ;
        int count = n;
        while(count!=0){
            int gewei = count%10;
            int shiwei = count/10;
            if(gewei < k){
                res += shiwei * base;
            }else if(gewei == k){
                res += shiwei * base + n % base + 1;
            }else{
                res += (shiwei+1) * base;
            }
            base *= 10;
            count = shiwei;
            lower_base = gewei;
        }
        if(k==0 && base > 10) res -= base/10;
        return res;
    }
    int digitCounts2 (int k, int n){
        int result = 0; 
        int base = 1;  //当前位数 初始化：个位
        while (n/base > 0 && k != 0) {
            int cur = (n / base) % 10; //当前位
            int low = n - (n/base) * base; //更低位
            int high = n/(base * 10); //更高位
            //当前位和k的关系不论如何，都有(更高位*base)的累加
            if (cur == k) {
                result += high * base + low + 1; //+1是什么意思呢
            } 
            else if (cur < k) {
                result += high * base;
            } 
            else {
                result += (high + 1) * base;
            }
            base *= 10;
        
        }
        // 只有高位存在才计0 因此0的数量等于 完整的高位数量
        // 但是由于 个位0 始终存在，因此res先+1
        if (k == 0) {
            result = 1;
            while (n/base > 0) {
                int cur = (n / base) % 10;
                int high = n/(base * 10);
                int low = n - (n/base) * base;
                result += high * base;
                base *= 10;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout << sol.digitCounts2(0, 10);
    return 0;
}