#include<iostream>
#include<unordered_set>
#include<vector>
#include<cstring>
using namespace std;

class Solution{
public:
    bool wordBreak(string & s, unordered_set<string> & wordDict){
        int m = s.size();
        int dp[m+1] ;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for(int i=1; i<=m; ++i){
            for(unordered_set<string>::iterator iter = wordDict.begin(); 
                    iter!= wordDict.end(); ++iter){
                int len = (*iter).size();
                
                if(i<len || dp[i-len]==0) continue;

                if(s.substr(i-len, len) == *iter) {
                    dp[i] = 1; 
                    break;
                }
                // auto sear = wordDict.find(s.substr(i-len+1, len));
                // if(sear != wordDict.end()) 
            }
        }
        return dp[m];
    }
    bool wordBreak_TEL(string & s, unordered_set<string>& wordDict){
        int h = s.size();
        bool res = canBreak(s, 0, h, wordDict);
        return res;
    }
    bool canBreak(string & s, int l, int h, unordered_set<string> & wordDict){
        auto sear = wordDict.find(s.substr(l, h-l));
        if(sear != wordDict.end()) return true;
        
        for(int mid=l+1; mid<h; ++mid){
            bool res1 = canBreak(s, l, mid, wordDict);
            bool res2 = canBreak(s, mid, h, wordDict);
            // bool res = canBreak(s, l, mid, wordDict) && canBreak(s, mid, h, wordDict);
            bool res = res1 && res2;
            if(res) return true;
        }
        return false;
    }
};

int main(){
    unordered_set<string> set = {"ab","aa"};
    string s = "aaab";
    // cout << s.substr(1,2);
    Solution sol;
    cout << sol.wordBreak_TEL(s, set) << endl;
    cout << sol.wordBreak(s, set) << endl;
    // cout << s.substr(1,2);
}