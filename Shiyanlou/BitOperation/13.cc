#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution{
private:
    vector<int> res;
    void help(int n){
        if(n==1)
            res = {0,1,2,3,4,5,6,7,8,9};
        else{
            help(n-1);
            int size = res.size();
            int base = pow(10,n-1);
            for(int i=1; i<=9; ++i){
                for(int j=0; j<size; ++j){
                    res.push_back(base*i+res[j]);
                }
            }
        }
    }
public:
    vector<int> numbersByRecursion(int n) {
        if(n!=0){
            help(n);
            res.erase(res.begin());
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int>res = sol.numbersByRecursion(2);
    for(vector<int>::iterator iter=res.begin(); iter!=res.end(); ++iter){
            cout << *iter <<' ';
        }
    return 0;
}