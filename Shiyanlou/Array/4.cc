#include<iostream>
#include<vector>
// #include<map>
#include<algorithm>
using namespace std;

class Solution{
private:
    int A[5] = {-3,1,1,-3,5};
public:
    int* subarraySum(){
        vector<pair<int,int>> sum(5);
        sum[0].first = A[0];
        sum[0].second = 0;
        for(int i=1; i<5; ++i){
            sum[i].first = A[i] + sum[i-1].first;
            sum[i].second = i;
        }
        sort(sum.begin(), sum.end());
        int delta = abs(sum[0].first - sum[1].first);
        int * res = new int[2];
        res[1] = max(sum[0].second,sum[1].second);
        res[0] = min(sum[0].second,sum[1].second);
        for(int i=1; i<5; ++i){
            if(abs(sum[i].first-sum[i+1].first) < delta){
                res[0] = max(sum[i].second, sum[i+1].second);
                res[1] = min(sum[i].second, sum[i+1].second);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    int *res = sol.subarraySum();
    cout << res[0] << ' ' << res[1] << endl;
    return 0;
}