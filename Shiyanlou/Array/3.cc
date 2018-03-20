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

int main(){
    Solution sol;
    int* res =  sol.subarraySum();
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}