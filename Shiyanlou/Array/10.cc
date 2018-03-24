#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> threeSum(vector<int>& S){
        vector<int> res;
        map<int, int> hash;
        sort(S.begin(), S.end());
        for(int i=0; i<S.size(); ++i){
            hash[S[i]] = i;
        }
        for(int i=0; i<S.size(); ++i){
            int K = -S[i];
            for(int j=i+1; j<S.size(); ++j){
                if(hash.find(K-S[j])!=hash.end()){
                    res.push_back(S[i]);
                    res.push_back(S[j]);
                    res.push_back(K-S[j]);
                    return res;
                }
            }
        }
        return res;
    }
};

int main(){
    int s[6] = {-1,0,1,2,-1,4};
    vector<int> S(s,s+6);
    Solution sol;
    vector<int> res = sol.threeSum(S);
    cout << res[0] << ' ' << res[1]<< ' ' << res[2]<< endl;
    return 0;
}