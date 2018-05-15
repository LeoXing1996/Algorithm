#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n<=0 || k<=0) return res;
        
        n_ = n;
        k_ = k;
        vector<int> list;
        dfs(res, list, 1);
        return res;
    }
private:
    int k_;
    int n_;
    void dfs(vector<vector<int> > & res, vector<int> & list, int pos){
        if(list.size() == k_){
            res.push_back(list);
            cout << "push" << endl;
        } else {
            for(int i=pos; i<=n_; ++i){
                list.push_back(i);
                dfs(res, list, i+1);
                list.pop_back();
            }
        }
    }
};

int main(){
    Solution sol;
    vector<vector<int>> res = sol.combine(4, 2);
    for(vector<vector<int>>::iterator iter=res.begin(); iter!=res.end(); ++iter){
        for(vector<int>::iterator iter_=iter->begin(); iter_!=iter->end(); ++iter_){
            cout << *iter_ << ' ';
        }
        cout << endl;
    }
}