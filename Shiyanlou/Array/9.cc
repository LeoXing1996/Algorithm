#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& A, int tar){
        map<int, int> hash;
        vector<int> res;
        for(int i=0; i<A.size(); ++i){
            if(hash.find(tar-A[i])!=hash.end()){
                res.push_back(hash[tar-A[i]]);
                res.push_back(i);
                return res;
            }
            hash[A[i]] = i;
        }

    }
};

int main(){
    int a[4] = {2,7,11,15};
    vector<int> A(a, a+4);
    Solution sol;
    vector<int> res = sol.twoSum(A, 9);
    for(vector<int>::iterator iter=res.begin();iter!=res.end();++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}