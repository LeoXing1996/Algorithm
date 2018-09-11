#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCut1(string s) {
        int dp[s.size()];
        dp[0] = 0;
        for(int i=1; i<s.size(); ++i){
            if(isPar(s, 0, i)) {dp[i] = 0;continue;}
            dp[i] = dp[i-1]+1;
            for(int j=1; j<i; ++j) // 判断从 j -> i 是否为回文序列
                if(isPar(s, j, i)) dp[i] = min(dp[j-1]+1, dp[i]);
        }
        return dp[s.size()-1];
    }
    int minCut2(string s){
        if(s.empty()) return 0;

        vector<vector<bool> > dp = getPar(s);
        int cut[s.size()+1];
        for(int i=0; i<s.size()+1; ++i) cut[i] = i-1;
        
        for(int i=2; i<=s.size(); ++i){
            for(int j=1; j<=i; ++j){
                if(dp[j-1][i-1]) cut[i] = min(cut[j-1]+1, cut[i]);
                
            }
        }

        return cut[s.size()];
    }
    vector< vector<bool> > getPar(string & S){
        vector<vector<bool> > dp(S.size(), vector<bool>(S.size(), true));
        for(int i=S.size()-1; i>=0; --i){
            for(int j=i+1; j<S.size(); ++j){
                if(j == i+1) dp[i][j] = S[i] == S[j];
                else dp[i][j] = (S[i] == S[j]) && dp[i+1][j-1];
            }
        }
        return dp;
        
        // int len = s.size();
        // vector<vector<bool> > mat = vector<vector<bool> >(len, vector<bool>(len, true));
        // for (int i = len; i >= 0; --i) {
        //     for (int j = i; j < len; ++j) {
        //         if (j == i) {
        //             mat[i][j] = true;
        //         } else if (j == i + 1) {
        //             mat[i][j] = (s[i] == s[j]);
        //         } else {
        //             mat[i][j] = ((s[i] == s[j]) && mat[i + 1][j - 1]);
        //         }
        //     }
        // }

        // return mat;
    }
private:
    bool isPar(string & S, int s, int e){
        int front = s;
        int rear = e;
        while(front < rear &&   S[front] == S[rear]){
            ++front;
            --rear;
        }
        if(front >= rear) return true;
        else return false;
    }
     
};

int main(){
    Solution sol;
    string s = "abad";
    vector< vector<bool> > dp = sol.getPar(s);
    for(vector< vector<bool> >::iterator iter = dp.begin(); iter != dp.end(); ++iter ){
        for(vector<bool>::iterator iter_ = (*iter).begin(); iter_ != (*iter).end(); ++iter_)
            cout << *iter_;
        cout << endl;
    }
    cout << sol.minCut2(s);
    // cout << sol.minCut2(s);
}
