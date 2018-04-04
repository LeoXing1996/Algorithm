#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int singleNumber(vector<int>&a){
        int res = 0;
        for(vector<int>::iterator iter = a.begin(); iter!=a.end();++iter){
            res = res ^ *iter ;
        }
        return res;
    }
};

int main(){
    vector <int> a ={1,2,2,1,3,4,3};
    Solution sol;
    cout << sol.singleNumber(a) <<endl;
    return 0;
}