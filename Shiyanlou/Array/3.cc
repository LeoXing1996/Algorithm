#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution{
    private:
        int a[6] = {1,4,20,3,10,5};
        int k = 33;
    public:
        int* subarraySum(){
            int* res = new int[2];
            map<int, int> hash;
            int sum = a[0];
            hash[sum] = 0;
            for(int i=1; i<6; ++i){
                sum += a[i];
                hash[sum] = i;
                if(hash.find(sum-k) != hash.end()){
                    res[0] = hash[sum-k] + 1;
                    res[1] = i;
                    return (int*) res;
                }
            }
        };
};

class Solution2{
    private:
        int A[6] = {1,4,20,3,10,5};
        int K = 33;
    public:
        int* subarraySum(){
            int sum[6];
            sum[0] = A[0];
            for(int i=1; i<6; ++i)
                sum[i] = sum[i-1] + A[i];
            int i=0;
            int j=0;
            while(sum[j]-sum[i]<K)
                ++j;

            while(sum[j]-sum[i]!=K){
                if(sum[j]-sum[i]>K)
                    ++i;
                if (sum[j]-sum[i]<K)
                    ++j;
            }
            int* res = new int[2];
            res[0] = i+1;
            res[1] = j;
            return res;
        }
        int* subarraySum2(){
            int sum = 0;
            int j = 0
            int i = 0;
            // todo     
};

int main(){
    Solution sol;
    Solution2 sol2;
    int* res1 =  sol.subarraySum();
    int* res2 = sol2.subarraySum();
    cout << res1[0] << ' ' << res1[1] << endl;
    cout << res2[0] << ' ' << res2[1] << endl;
    return 0;
}